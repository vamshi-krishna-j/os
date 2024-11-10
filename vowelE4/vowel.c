%
{
    int vowels = 0, capitals = 0, lines = 1, tabs = 0, spaces = 0;
    %
}

% %
    [aeiouAEIOU]
{ vowels++; }
        [A - Z] { capitals++; }
\n { lines++; }
\t { tabs++; }
" " { spaces++; }
.; /* Ignore other characters */
% %

    int main()
{
    yyin = fopen("input.txt", "r");
    yylex();
    fclose(yyin);

    printf("Vowels: %d\n", vowels);
    printf("Capital letters: %d\n", capitals);
    printf("Lines: %d\n", lines);
    printf("Tabs: %d\n", tabs);
    printf("Spaces: %d\n", spaces);

    return 0;
}
