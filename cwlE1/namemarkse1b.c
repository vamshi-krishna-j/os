#include <stdio.h>

int main()
{
    char name[50];
    int marks;
    int num;

    printf("How many student data do you want to store? ");
    scanf("%d", &num);

    FILE *Anosh;
    Anosh = fopen("../exp1.txt", "w");

    if (!Anosh)
    {
        printf("File not opening\n");
        return 1;
    }

    for (int i = 0; i < num; i++)
    {
        printf("%d. Enter student name: ", i + 1);
        scanf("%s", name);

        printf("%d. Enter student marks: ", i + 1);
        scanf("%d", &marks);

        fprintf(Anosh, "%s %d\n", name, marks);
    }

    fclose(Anosh);
    printf("Data stored successfully in exp1.txt\n");
    return 0;
}
