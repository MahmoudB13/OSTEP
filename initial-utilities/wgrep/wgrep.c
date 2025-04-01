#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char* line = NULL;
    size_t len = 0;
    ssize_t nread;

    // Check if at least a search term is provided
    if(argc < 2)
    {
        fprintf(stdout, "wgrep: searchterm [file ...]\n");
        exit(1);
    }

    // If no file is provided, read from standard input
    if(argc == 2)
    {
        while ((nread = getline(&line, &len, stdin)) != -1)
        {
            char* str = strstr(line, argv[1]); // Check if the search term exists in the line
            if(str != NULL)
            {
                printf("%s", line); // Print the matching line
            }
        }
        free(line);
        return 0;
    }

    // Iterate through the provided files
    int i = 2;
    while(i < argc)
    {
        FILE *fp = fopen(argv[i], "r");
        if(fp == NULL)
        {
            fprintf(stdout, "wgrep: cannot open file\n");
            exit(1);
        }
        
        // Read lines from the file and check for the search term
        while ((nread = getline(&line, &len, fp)) != -1) 
        {
            char* str = strstr(line, argv[1]);
            if(str != NULL)
            {
                printf("%s", line);
            }
        }
        fclose(fp); // Close the file after reading
        i++;
    }
    
    free(line); // Free allocated memory
    return 0;
}

