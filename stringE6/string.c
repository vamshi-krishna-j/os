#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int state = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (state)
        {
        case 0: // Start state
            if (str[i] == 'a')
                state = 1;
            else
                state = -1; // Invalid
            break;
        case 1: // Seen 'a'
            if (str[i] == 'a')
                state = 1; // Stay in same state
            else if (str[i] == 'b')
                state = 2;
            else
                state = -1;
            break;
        case 2: // Seen 'ab'
            if (str[i] == 'b')
                state = 2; // Stay in same state
            else
                state = -1;
            break;
        }
        if (state == -1)
            break; // No need to continue if invalid
    }

    if (state == 1)
        printf("String matches 'a*'\n");
    else if (state == 2)
        printf("String matches 'a*b+'\n");
    else if (state == 3)
        printf("String matches 'abb'\n");
    else
        printf("String does not match any pattern\n");

    return 0;
}
