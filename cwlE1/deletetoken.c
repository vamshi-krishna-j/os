#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char filename[100], line[100], token[100];
    int i, j;

    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        j = 0;
        for (i = 0; i < strlen(line); i++)
        {
            if (isspace(line[i]))
            {
                if (j > 0)
                {
                    token[j] = '\0';
                    printf("%s\n", token);
                    j = 0;
                }
            }
            else if (ispunct(line[i]))
            {
                if (j > 0)
                {
                    token[j] = '\0';
                    printf("%s\n", token);
                    j = 0;
                }
                // Print the punctuation as a separate token
                printf("%c\n", line[i]);
            }
            else
            {
                token[j++] = line[i];
            }
        }
        if (j > 0)
        {
            token[j] = '\0';
            printf("%s\n", token);
        }
    }

    fclose(fp);
    return 0;
}

// input
//  #include <stdio.h>

// int main() {
//     printf("Hello, world!\n");
//     return 0;
// }
