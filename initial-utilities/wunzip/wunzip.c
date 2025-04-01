#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    // Check if at least one file is provided
    if(argc < 2)
    {
        fprintf(stdout, "wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    
    int i = 1;
    while(i < argc)
    {
        FILE *fp = fopen(argv[i], "r"); // Open file in read mode
        if(fp == NULL)
        {
            fprintf(stdout, "wzip: cannot open file\n");
            exit(1);
        }
        
        int count; // Variable to store the number of times a character appears
        char buffer; // Variable to store the character read from the file
        
        while(fread(&count, sizeof(int), 1, fp)) // Read the count of the character
        {
            fread(&buffer, sizeof(char), 1, fp); // Read the character itself
            while(count--) // Print the character 'count' times
            {
                printf("%c", buffer);
            }
        }
        
        fclose(fp); // Close the file after processing
        i++;
    }
}

