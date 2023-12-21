#include "helper.h"
#include "my_string.h"


int countWords(const char* text)
{
    int words = 0;
    int isInSpace = 1;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' || text[i] == '\t' || text[i] == '\n')
        {
            isInSpace = 1;
        }
        else
        {
            if (isInSpace)
            {
                words++;
                isInSpace = 0;
            }
        }
    }

    return words;
}

char* findLongestSentence(const char* text)
{
    const char* start = text;
    const char* end = text;
    const char* longestStart = text;
    int maxWordCount = 0;
    int curWordCount = 0;

    char sentence[1000];
    char longest[1000];
    int maxLength = 0;

    while (*end != '\0') {
        if (*end == '.' || *end == '!' || *end == '?' || *(end + 1) == '\0')
        {
            int length = end - start + 1;
            for (int i = 0; i < length; i++)
            {
                sentence[i] = start[i];
            }
            sentence[length] = '\0';

            int wordsInSentence = countWords(sentence);
            if (wordsInSentence > maxWordCount)
            {
                maxWordCount = wordsInSentence;
                int sentenceLength = my_strlen(sentence);
                if (sentenceLength >= maxLength)
                {
                    maxLength = sentenceLength;
                    my_strcpy(longest, sentence);
                }
            }

            start = end + 1;
        }
        end++;
    }

    char* longestSentence = (char*)malloc(maxLength + 1);
    if (longestSentence == NULL)
    {
        return NULL;
    }

    my_strcpy(longestSentence, longest);
    return longestSentence;
}

void correct(int* checkNumber)
{
    int enterNumber = scanf("%d", checkNumber);
    while (enterNumber == 0)
    {
        scanf("Enter another number");
        scanf("%*[^\n]");
        enterNumber = scanf("%d", checkNumber);
    }
}
