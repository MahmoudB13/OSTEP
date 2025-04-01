#include <stdio.h>
#include <stdlib.h>

#define buffer_size 100  // Define a fixed buffer size for reading file contents

int main(int argc, char** argv)
{
    // Check if at least one filename argument is provided
    if(argc < 2)
    {
        exit(0); // If no arguments, exit silently
    }
    
    // Allocate memory for the buffer used to read file contents
    char* buffer = (char*)malloc(buffer_size * sizeof(char));
    if(buffer == NULL)
    {
        fprintf(stderr, "error: memory allocation failed.\n");
        exit(1); // Exit with error if memory allocation fails
    }
    
    int i = 1; // Start from the first filename argument
    while(i < argc)
    {
        // Open the file in read mode
        FILE *fp = fopen(argv[i], "r");
        if(fp == NULL)
        {
            fprintf(stdout, "wcat: cannot open file\n");
            free(buffer); // Free allocated memory before exiting
            exit(1); // Exit with error if file cannot be opened
        }
        
        // Read file line by line and print to stdout
        while(fgets(buffer, buffer_size, fp))
            printf("%s", buffer);
        
        fclose(fp); // Close the file after reading
        i++; // Move to the next file argument
    }
    
    free(buffer); // Free the allocated memory before exiting
    return 0; // Exit successfully
}

