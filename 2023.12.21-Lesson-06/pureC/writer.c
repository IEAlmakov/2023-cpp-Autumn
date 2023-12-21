#include "writer.h"

char* readFromFile(const char* filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*) malloc(length + 1);
    if (buffer == NULL)
    {
        fclose(file);
        return NULL;
    }
    fread(buffer, 1, length, file);
    buffer[length] = '\0';

    fclose(file);
    return buffer;
}

void writeWordCountToFile(int wordCount, const char* filename)
{
    FILE *file = fopen(filename, "w");
    if (file != NULL)
    {
        fprintf(file, "Number of words: %d\n", wordCount);
        fclose(file);
    }
}

void writeLongestSentenceToFile(const char* longestSentence, const char* filename)
{
    FILE *file = fopen(filename, "a");
    if (file != NULL)
    {
        fprintf(file, "Longest sentence: %s\n", longestSentence);
        fclose(file);
    }
}

