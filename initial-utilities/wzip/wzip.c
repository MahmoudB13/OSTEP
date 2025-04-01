#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    // Check if at least one file is provided
    if(argc < 2)
    {
        fprintf(stdout, "wzip: file1 [file2 ...]\n");
        exit(1);
    }

    char temp = '\0'; // Variable to store the current character being processed
    int count = 0; // Count of consecutive occurrences of a character

    int i = 1;
    while(i < argc)
    {
        FILE *fp = fopen(argv[i], "r"); // Open file in read mode
        if(fp == NULL)
        {
            fprintf(stdout, "wzip: cannot open file\n");
            exit(1);
        }

        char buffer; // Variable to store the character read from the file
        while(fread(&buffer, sizeof(char), 1, fp)) // Read file character by character
        {
            if(temp == buffer) // If the character matches the previous one, increment count
                count++;
            else
            {
                if(count > 0) // If a different character is found, write the previous character's count
                {
                    fwrite(&count, sizeof(int), 1, stdout);
                    fwrite(&temp, sizeof(char), 1, stdout);
                }
                count = 1; // Reset count for the new character
                temp = buffer; // Update temp to the new character
            }
        }
        fclose(fp); // Close the file after processing
        i++;
    }

    // Write the last character and its count if any
    if (count > 0) 
    {
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&temp, sizeof(char), 1, stdout);
    }

    return 0;
}

