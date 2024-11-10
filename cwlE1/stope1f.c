#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

int main()
{
    char drop_words[MAX_WORDS][MAX_WORD_LENGTH], word[MAX_WORD_LENGTH];
    int drop_word_count = 0, found;
    int word_match[MAX_WORDS] = {0};

    FILE *dfp = fopen("drop.txt", "r");
    FILE *sfp = fopen("source.txt", "r");
    FILE *ofp = fopen("output.txt", "w");
    FILE *rfp = fopen("report.txt", "w");

    if (!dfp || !sfp || !ofp || !rfp)
    {
        printf("Error opening files\n");
        return 1;
    }

    // Read drop words from "drop.txt" and store them in the array
    while (fscanf(dfp, "%s", drop_words[drop_word_count]) != EOF)
    {
        drop_word_count++;
    }

    // Process each word in "source.txt" and remove drop words
    while (fscanf(sfp, "%s", word) != EOF)
    {
        found = 0;

        // Check if the word is in the drop list
        for (int i = 0; i < drop_word_count; i++)
        {
            if (strcmp(word, drop_words[i]) == 0)
            {
                word_match[i]++;
                found = 1;
                break;
            }
        }

        // If the word is not a drop word, write it to "output.txt"
        if (!found)
        {
            fprintf(ofp, "%s ", word); // Fixed format specifier from "s" to "%s "
        }
    }

    // Write the match report to "report.txt"
    fprintf(rfp, "Word-wise match report:\n");
    for (int i = 0; i < drop_word_count; i++)
    {
        fprintf(rfp, "Word '%s' matched %d times\n", drop_words[i], word_match[i]);
    }

    // Close all open files
    fclose(dfp);
    fclose(sfp);
    fclose(ofp);
    fclose(rfp);

    return 0;
}

// drop. txt
//  is
//  the
//  a
//  and

// source.txt (Original text):
// This is a simple example of a C program. The program removes the words that are in the
// drop list.
// And it produces two files: an output file and a report file