#include <stdio.h>
int main()
{
    FILE *fp;
    char c;
    int ch = 0, words = 0, lines = 0;
    fp = fopen("../exp1.txt", "r");
    if (!fp)
    {
        printf("Unable to open file");
        return 1;
    }
    c = fgetc(fp);
    while (c != EOF)
    {
        ch = ch + 1;
        if (c == ' ')
            words++;
        if (c == '\n')
            lines++;
    }
    fclose(fp);
    printf("%d %d %d", ch, words, lines);
    return 0;
}