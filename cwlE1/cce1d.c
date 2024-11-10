#include <stdio.h>

int main()
{
    FILE *f1, *f2;
    f1 = fopen("exp1.txt", "r");
    f2 = fopen("david.txt", "w");

    if (!f1)
    {
        printf("Source file is not opening\n");
        return 1;
    }
    if (!f2)
    {
        printf("Destination file is not opening\n");
        fclose(f1);
        return 1;
    }

    char c;

    while ((c = fgetc(f1)) != EOF)
    {
        fputc(c, f2);
    }

    fclose(f1);
    fclose(f2);

    printf("File has been copied successfully.\n");
    return 0;
}
