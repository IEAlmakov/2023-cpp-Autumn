#ifndef WRITER_H
#define WRITER_H

#include <stdio.h>
#include <stdlib.h>

char* readFromFile(const char*);
void writeWordCountToFile(int, const char*);
void writeLongestSentenceToFile(const char*, const char*);
#endif // WRITER_H
