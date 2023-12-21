#include "writer.h"
#include "helper.h"
#include "my_string.h"

int main()
{
    FILE* input_file = fopen("in.txt", "r");
    fclose(input_file);
    char* text = readFromFile("in.txt");
    if (text != NULL) {
        int wordCount = countWords(text);
        char* longestSentence = findLongestSentence(text);
        if (longestSentence != NULL) {
            printf("Number of words: %d\n", wordCount);
            printf("Longest sentence: %s\n", longestSentence);
            writeWordCountToFile(wordCount, "out.txt");
            writeLongestSentenceToFile(longestSentence, "out.txt");
            free(longestSentence);
        }
        free(text);
    }
    else
    {
        printf("Failed to read file 'in.txt'.\n");
    }
    int exit = 0;
    while (!exit)
    {
        char str1[1000];
        char str2[500];
        char *substr;
        int choice = 0;
        printf("Choose a function\n");
        printf("1 – strcat()\n");
        printf("2 – strstr()\n");
        printf("3 – substr()\n");
        printf("4 – strcmp()\n");
        printf("5 – strmult()\n");
        printf("6 – Exit\n");
        correct(&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                my_strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            case 2:
                printf("Enter the main string: ");
                scanf("%s", str1);
                printf("Enter the substring to search for: ");
                scanf("%s", str2);
                char *ptr = my_strstr(str1, str2);
                if (ptr != NULL)
                {
                    printf("'%s' is found in '%s' at position %ld\n", str2, str1, ptr - str1);
                }
                else
                {
                    printf("'%s' is not found in '%s'\n", str2, str1);
                }
                break;
            case 3:
                printf("Enter the string: ");
                scanf("%s", str1);
                int start_index = 0;
                printf("Enter the starting index: ");
                scanf("%d", &start_index);
                int length = 0;
                printf("Enter the length of the substring: ");
                scanf("%d", &length);
                substr = my_substr(str1, start_index, length);
                printf("Substring: %s\n", substr);
                free(substr);
                break;
            case 4:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                int result = my_strcmp(str1, str2);
                if (result == 0)
                {
                    printf("The strings are equal.\n");
                }
                else if (result < 0)
                {
                    printf("String 1 is less than string 2.\n");
                }
                else
                {
                    printf("String 1 is greater than string 2.\n");
                }
                break;
            case 5:
                printf("Enter the string: ");
                scanf("%s", str1);
                int multiplier = 0;
                printf("Enter the multiplier: ");
                correct(&multiplier);
                for (int i = 0; i < multiplier; i++)
                {
                    printf("%s", str1);
                }
                printf("\n");
                break;
            case 6:
                exit = 1;
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}

