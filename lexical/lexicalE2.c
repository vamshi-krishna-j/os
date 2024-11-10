#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp = fopen("input.txt", "r"), *idfp = fopen("identifiers.txt", "w"),
         *kwfp = fopen("keywords.txt", "w"), *opfp = fopen("operators.txt", "w");
    char c, buffer[50];
    int i = 0;

    if (fp == NULL || idfp == NULL || kwfp == NULL || opfp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        if (isspace(c))
            continue; // Ignore spaces, tabs, newlines
        if (c == '/')
        { // Handle comments
            if ((c = fgetc(fp)) == '/')
                while ((c = fgetc(fp)) != '\n')
                    ;
            else if (c == '*')
                while ((c = fgetc(fp)) != '*' || (c = fgetc(fp)) != '/')
                    ;
            else
                ungetc(c, fp);
            continue;
        }
        if (isalpha(c))
        { // Identifiers and keywords
            buffer[i++] = c;
            while (isalnum(c = fgetc(fp)))
                buffer[i++] = c;
            buffer[i] = '\0';
            ungetc(c, fp);
            // (Add keyword check here - compare buffer with keyword list)
            fprintf(idfp, "%s\n", buffer);
            i = 0;
        }
        else if (ispunct(c))
        { // Operators
            fprintf(opfp, "%c\n", c);
        }
        // Handle numbers and other token types similarly
    }

    fclose(fp);
    fclose(idfp);
    fclose(kwfp);
    fclose(opfp);
    return 0;
}

// input
//  int main() {
//      int a = 5;
//      a = a + 1;
//      return a;
//  }
