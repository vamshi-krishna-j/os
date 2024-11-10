#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 10
#define MAX_STACK 100
#define MAX_INPUT 100

typedef struct
{
    char lhs;
    char rhs[MAX_SYMBOLS];
} Production;

Production productions[MAX_PRODUCTIONS];
int production_count = 0;

void add_production(char lhs, const char *rhs)
{
    productions[production_count].lhs = lhs;
    strcpy(productions[production_count].rhs, rhs);
    production_count++;
}

void print_productions()
{
    for (int i = 0; i < production_count; i++)
    {
        printf("%c -> %s\n", productions[i].lhs, productions[i].rhs);
    }
}

void parse(char *input)
{
    int stack[MAX_STACK];
    int top = -1;
    stack[++top] = 0;

    char *token = strtok(input, " ");
    char action[MAX_INPUT];

    while (token != NULL)
    {
        printf("Current token: %s\n", token);

        if (strcmp(token, "id") == 0)
        {
            strcpy(action, "Shift");
            stack[++top] = 1;
        }
        else if (strcmp(token, "+") == 0)
        {
            strcpy(action, "Shift");
            stack[++top] = 2;
        }
        else if (strcmp(token, "(") == 0)
        {
            strcpy(action, "Shift");
            stack[++top] = 3;
        }
        else if (strcmp(token, ")") == 0)
        {
            strcpy(action, "Reduce E -> T");
            top--;
        }
        else
        {
            printf("Error: Unrecognized token %s\n", token);
            return;
        }

        printf("Action: %s, Stack: ", action);
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");

        token = strtok(NULL, " ");
    }

    printf("Parsing complete.\n");
}

int main()
{
    add_production('E', "E+T");
    add_production('E', "T");
    add_production('T', "T*F");
    add_production('T', "F");
    add_production('F', "(E)");
    add_production('F', "id");

    printf("Grammar productions:\n");
    print_productions();

    char input[MAX_INPUT];
    printf("Enter input string (tokens separated by space): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    parse(input);
    return 0;
}
// Input:
// Enter input string (tokens separated by space): id + id * id
