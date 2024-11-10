#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;

    printf("Enter an operator: ");
    scanf(" %c", &c); // Note the space before %c to consume whitespace

    if (ispunct(c))
    {
        switch (c)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
        case '<':
        case '>':
        case '!':
        case '&':
        case '|':
        case '^':
            printf("%c is a valid operator\n", c);
            break;
        default:
            printf("%c is not a valid operator\n", c);
        }
    }
    else
    {
        printf("Invalid input. Please enter an operator.\n");
    }

    return 0;
}
