#ifndef ARRAY_H
#define ARRAY_H

void arrayInitialization (int** array, int* len);
void arraySwitch(int** array, int len);
void arrayDeleteDuplicate(int** array, int* len);
void arrayReverse(int** array, int len);
void arrayBinarySort(int** array, int len);
void arrayDelete (int** array, int* len, int index);
void arrayAdd(int** array, int* len, int index, int element);
void arrayCreate(int** array, int len);

#endif // ARRAY_H
