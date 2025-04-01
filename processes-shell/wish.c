#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int path_count = 1;
char **path = NULL;
char error_message[30] = "An error has occurred\n";

void
free_path ()
{
    for (int i = 0; i < path_count; i++)
    {
	free (path[i]);
    }
    free (path);
}

void
execute_command (char *line)
{
    // Number of parallel commands:
    int count = 0;
    char **commands = (char **) calloc (32 + 1, sizeof (char *));

    char *token = strtok (line, "&");
    while (token != NULL)
    {
	while (*token == ' ')
	    token++;
	if (*token != '\0')
	    commands[count++] = token;
	token = strtok (NULL, "&");
    }

    pid_t pids[count];

    for (int i = 0; i < count; i++)
    {
	// Check for redirection:
	int redirection_flag = (strchr (commands[i], '>') != NULL);
	char *cmd = strtok (commands[i], ">");
	char *redirection_file = NULL;
	if (cmd != NULL && redirection_flag)
	{
	    redirection_file = strtok (NULL, "\n");
	    if (redirection_file == NULL
		|| strchr (redirection_file, '>') != NULL)
	    {
		write (STDERR_FILENO, error_message, strlen (error_message));
		continue;
	    }

	    // Skip leading spaces
	    while (*redirection_file == ' ')
		redirection_file++;

	    // Check if there's an actual filename
	    if (*redirection_file == '\0')
	    {
		write (STDERR_FILENO, error_message, strlen (error_message));
		continue;
	    }
	    redirection_file = strtok (redirection_file, " ");	// Get first token after '>'
	    while (redirection_file != NULL && *redirection_file == ' ')
		redirection_file = strtok (NULL, " ");
	    if (strtok (NULL, " ") != NULL)
	    {
		write (STDERR_FILENO, error_message, strlen (error_message));
		continue;
	    }
	}

	// Parse the command:
	char **w_argv = (char **) calloc (32 + 1, sizeof (char *));
	int w_argc = 0;
	if ((w_argv[w_argc] = strtok (cmd, " ")) != NULL)
	{
	    w_argc++;
	    while ((w_argv[w_argc] = strtok (NULL, " ")) != NULL)
		w_argc++;
	}

	w_argv[w_argc] = NULL;

	if (w_argc == 0)
	{
	    write (STDERR_FILENO, error_message, strlen (error_message));
	    free (w_argv);
	    continue;
	}

	// Exit wish:
	if (strcmp (w_argv[0], "exit") == 0)
	{
	    if (w_argc > 1)
	    {
		write (STDERR_FILENO, error_message, strlen (error_message));
	    }
	    free (w_argv);
	    free (commands);
	    free (line);
	    free_path ();
	    exit (0);
	}

	// Change directory:
	if (strcmp (w_argv[0], "cd") == 0)
	{
	    if (w_argc != 2 || chdir (w_argv[1]) != 0)
		write (STDERR_FILENO, error_message, strlen (error_message));
	    free (w_argv);
	    free (commands);
	    return;
	}

	// Built-in path command:
	if (strcmp (w_argv[0], "path") == 0)
	{
	    free_path ();
	    path = (char **) calloc (w_argc, sizeof (char *));
	    path_count = 0;
	    for (int i = 0; i < w_argc - 1; i++)
	    {
		path[i] = strdup (w_argv[i + 1]);
		path_count++;
	    }
	    free (w_argv);
	    free (commands);
	    return;
	}

	// Find absolute path:
	int found_path = 0;
	char *real_path = (char *) calloc (256 + 1, sizeof (char));
	for (int i = 0; i < path_count; i++)
	{
	    char *check_path =
		(char *) malloc (strlen (path[i]) + strlen (w_argv[0]) + 2);
	    strcpy (check_path, path[i]);

	    if (path[i][strlen (path[i]) - 1] != '/')
		strcat (check_path, "/");

	    strcat (check_path, w_argv[0]);
	    if (access (check_path, X_OK) == 0)
	    {
		found_path = 1;
		strcpy (real_path, check_path);
		free (check_path);
		break;
	    }
	    free (check_path);
	}
	if (!found_path)
	{
	    write (STDERR_FILENO, error_message, strlen (error_message));
	    free (w_argv);
	    free (real_path);
	    return;
	}

	// Create a new process:
	pids[i] = fork ();

	// Child:
	if (pids[i] == 0)
	{
	    if (redirection_flag == 1)
	    {
		int fd = open (redirection_file, O_CREAT | O_WRONLY | O_TRUNC,
			       S_IRWXU);
		if (fd == -1)
		{
		    write (STDERR_FILENO, error_message,
			   strlen (error_message));
		    free (real_path);
		    free (w_argv);
		    exit (1);
		}
		dup2 (fd, STDOUT_FILENO);
		dup2 (fd, STDERR_FILENO);
		close (fd);
	    }
	    execv (real_path, w_argv);
	    write (STDERR_FILENO, error_message, strlen (error_message));
	    free (real_path);
	    free (w_argv);
	    exit (1);
	}
	else if (pids[i] < 0)
	{
	    write (STDERR_FILENO, error_message, strlen (error_message));
	    free (w_argv);
	    free (real_path);
	    free (commands);
	    exit (1);
	}
	free (w_argv);
	free (real_path);
    }
    while (waitpid (-1, NULL, 0) > 0);
    free (commands);
}

int
main (int argc, char **argv)
{
    path = (char **) calloc (32 + 1, sizeof (char *));
    path[0] = strdup ("/bin/");

    // Batch mode:
    if (argc == 2)
    {
	FILE *file = fopen (argv[1], "r");
	if (!file)
	{
	    write (STDERR_FILENO, error_message, strlen (error_message));
	    exit (1);
	}

	char *line = NULL;
	size_t len = 0;

	while (getline (&line, &len, file) != -1)
	{
	    if (strcmp (line, "\n") == 0)
		continue;
	    line = strtok (line, "\n");
	    execute_command (line);
	}

	free (line);
	fclose (file);
	free_path ();
	exit (0);
    }

    // Interactive mode:
    else if (argc == 1)
    {
	while (1)
	{
	    printf ("wish> ");
	    char *line = NULL;
	    size_t len = 0;
	    getline (&line, &len, stdin);
	    if (strcmp (line, "\n") == 0)
	    {
		free (line);
		continue;
	    }
	    line = strtok (line, "\n");
	    execute_command (line);
	    free (line);
	}
    }
    else
    {
	write (STDERR_FILENO, error_message, strlen (error_message));
	exit (1);
    }
    free_path ();
}
