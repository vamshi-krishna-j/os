<--------------------------------------------------------------->
4a. Write a Lex Program to find whether a given letter is a vowel or not.

%{
  #include<stdio.h>
%}

%%
[aeiouAEIOU]  printf("%s is a vowel.\n", yytext); 
[a-zA-Z]      printf("%s is consonant.\n", yytext);
.             printf("%s is invalid", yytext);
%%

int main() {
  yylex();
  return 0;
}


<--------------------------------------------------------------->
4b. Write a Lex Program to find Capital letters.

%{
#include <stdio.h>
%}

%%
[A-Z]   { printf("%s is a capital letter.\n", yytext); }
.       { ; }  /* Ignore other characters */
%%

int main() {
    yylex();
    return 0;
}


<--------------------------------------------------------------->
4c. Write a Lex program to count the number of lines,  tabs, and spaces used in the input.

%{
#include <stdio.h>
int line = 0, tab = 0, space = 0;
%}

%%
\n      { line++; }
\t      { tab++; }
" "     { space++; }
.       { ; }  
%%

int main() {
  printf("Enter input (Ctrl+D to end input):\n");
  yylex();
  printf("Lines: %d, Tabs: %d, Spaces: %d\n", line, tab, space);
  return 0;
}

<--------------------------------------------------------------->
4d.Write a Lex program to take input from a file and remove multiple spaces, newline and tab and write output in a separate file.

%{
#include <stdio.h>
#include <stdlib.h>
FILE *yyin, *yyout;
%}

%%
[ \t\n]+                              ; //this is intentionally kept
.	        fputc(yytext[0], yyout);
%%

int main() {
  yyin = fopen("4d.txt", "r");
  yyout = fopen("output.txt", "w");
  yylex();
  return 0;
}