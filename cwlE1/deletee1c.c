#include <stdio.h>

int main()
{
    FILE *fp, *temp;
    char buffer[256];
    int line = 1, line_to_delete;

    printf("Enter the line number to delete: ");
    scanf("%d", &line_to_delete);

    fp = fopen("exp1.txt", "r");
    temp = fopen("temp.txt", "w");

    if (!fp || !temp)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp))
    {
        if (line != line_to_delete)
        {
            fputs(buffer, temp);
        }
        line++;
    }

    fclose(fp);
    fclose(temp);

    remove("exp1.txt");
    rename("temp.txt", "exp1.txt");

    printf("Line %d deleted successfully.\n", line_to_delete);
    return 0;
}
