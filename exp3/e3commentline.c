#include <stdio.h>

int main()
{
    FILE *fp = fopen("e3input.c", "r"),
         *outfp = fopen("comments.txt", "w");
    char c, prev = 0;

    if (fp == NULL || outfp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '/' && prev == '/')
        { // Single-line comment
            while ((c = fgetc(fp)) != '\n')
                fputc(c, outfp);
            fputc('\n', outfp);
        }
        else if (c == '*' && prev == '/')
        { // Multi-line comment
            while ((c = fgetc(fp)) != '*' || (prev = fgetc(fp)) != '/')
            {
                fputc(c, outfp);
                c = prev;
            }
            fputc('/', outfp);
        }
        prev = c;
    }

    fclose(fp);
    fclose(outfp);
    return 0;
}
