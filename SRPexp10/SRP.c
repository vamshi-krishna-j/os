#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// Function prototypes
void push(char item);
char pop(void);
int call(char c);
void printRemainingInput(int index);
void printStack(int top);
void displayResult(char *cmp, char *str2);

// Stack and input-related variables
char stack[MAX], input[10];
int top = -1;

void main()
{
    char cmp[3] = "", str2[15] = "";
    int i = 0, cn = 0;
    FILE *ptr;

    printf("\n\nEnter the expression:\n");
    scanf("%s", input);

    push('0');
    printf("\n\n\t STACK \t\t COMPARISON \t\t OUTPUT \n\n");

    do
    {
        printStack(top);
        printf("\t\t");
        printRemainingInput(i);

        if (strcmp(cmp, "1$") == 0)
        {
            strcpy(str2, "accepted");
            printf("\n\nThe input is accepted\n");
            exit(0);
        }
        else
        {
            cmp[0] = stack[top];
            cmp[1] = input[i];
            cmp[2] = '\0';

            if ((ptr = fopen("lrtable.txt", "r")) == NULL)
            {
                printf("\n\nFile cannot be opened.\n");
                exit(1);
            }

            int matched = 0;
            while (fscanf(ptr, "%s %s", cmp, str2) != EOF)
            {
                if (strcmp(cmp, str2) == 0)
                {
                    if (str2[0] == 's')
                    {
                        push(input[i]);
                        push(str2[1]);
                        i++;
                        matched = 1;
                        break;
                    }
                    else if (str2[0] == 'r')
                    {
                        cn = call(str2[1]);
                        for (int k = 0; k < (cn * 2); k++)
                            pop();
                        push(str2[1]);
                        matched = 1;
                        break;
                    }
                    else if (strcmp(str2, "0") == 0)
                    {
                        printf("\n\nThe string is not accepted\n");
                        fclose(ptr);
                        exit(1);
                    }
                }
            }
            fclose(ptr);

            if (!matched)
            {
                printf("\n\nNo matching rule found.\n");
                exit(1);
            }
        }
        displayResult(cmp, str2);
    } while (input[i] != '\0');
}

int call(char c)
{
    int count = 0;
    switch (c)
    {
    case '1':
        strcpy(str2, "E->E+T");
        count = 3;
        break;
    case '2':
        strcpy(str2, "E->T");
        count = 1;
        break;
    case '3':
        strcpy(str2, "T->T*F");
        count = 3;
        break;
    case '4':
        strcpy(str2, "T->F");
        count = 1;
        break;
    case '5':
        strcpy(str2, "F->(E)");
        count = 3;
        break;
    case '6':
        strcpy(str2, "F->id");
        count = 1;
        break;
    }
    return count;
}

void push(char item)
{
    if (top >= MAX - 1)
    {
        printf("\n\nStack overflow\n");
    }
    else
    {
        stack[++top] = item;
    }
}

char pop(void)
{
    if (top == -1)
    {
        printf("\n\nStack underflow\n");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

void printRemainingInput(int index)
{
    for (int i = index; input[i] != '\0'; i++)
    {
        printf("%c", input[i]);
    }
}

void printStack(int top)
{
    for (int i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }
}

void displayResult(char *cmp, char *str2)
{
    printf("\t\t%s\t\t%s\n", cmp, str2);
}
