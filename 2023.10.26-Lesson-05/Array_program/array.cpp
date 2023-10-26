#include "array.h"
#include "correct.h"

void printMenu()
{
    std::cout << "1 - Выйти из программы" << std::endl;
    std::cout << "2 - Вывести массив" << std::endl;
    std::cout << "3 - Добавить элемент в массив" << std::endl;
    std::cout << "4 - Удалить элемент из массива" << std::endl;
    std::cout << "5 - Отсортировать массив по возрастанию" << std::endl;
    std::cout << "6 - Развернуть массив" << std::endl;
    std::cout << "7 - Поменять местами максимальный и минимальный элемент массива" << std::endl;
    std::cout << "8 - Удалить из массива все дубликаты" << std::endl;
    std::cout << "9 - Создание(Пересоздание) массива произвольного размера и заполнение его" << std::endl;
}

void arrayCreate(int** array, int* len)
{
    int len1 = 0;
    free(*array);

    std::cout << "Введите пожалуйста размер массива" << std::endl;
    correct(&len1);

    *len = len1;
    *array = (int *) malloc (sizeof(int) * (*len));

    if (array == NULL)
    {
        std::cout << "Массив не получилось создать" << std::endl;
    }

    for (int i = 0; i < *len; i++)
    {
        std::cout << "Введите элемент массива" << std::endl;
        correct(&(*array)[i]);
        std::cout << std::endl;
    }
}

void arrayPrint (int* array, int len)
{
    if (array == NULL)
    {
        std::cout << "Массива не существует" << std::endl;
    }
    else
    {
        std::cout << "Элементы массива" << std::endl;
        for (int i = 0; i < len; i++)
        {
            std::cout << array[i] << std::endl;
        }
    }
}

void arrayAdd(int** array, int* len)
{
    if (array == NULL)
    {
        std::cout << "Проинициализируйте пожалуйста массив" << std::endl;
    }

    else {
        std::cout << "Введите индекс элемента массива" << std::endl;
        std::cout << "!!!! Индекс элемента >= 0 !!!!!" << std::endl;

            int index = -1;
        while (index < 0)
        {
            correct(&index);
        }

        int element = 0;
        std::cout << "Введите элемент массива" << std::endl;
        correct(&element);

        if (index < (*len))
        {
            (*array)[index] = element;
        }
        else
        {
            *array = (int*) realloc(*array, ((*len) + 1) * sizeof(int));
            (*array)[*len] = element;
            *len = *len + 1;
        }
    }
}

void arrayDelete (int** array, int* len)
{
    if (array == NULL)
    {
        std::cout << "Массива не существует" << std::endl;
    }

    else {
        std::cout << "Введите индекс элемента массива" << std::endl;
        std::cout << "!!!! Индекс элемента >= 0 !!!!!" << std::endl;

            int index = -1;
        while (index < 0)
        {
            correct(&index);
        }

        if (index < *len)
        {
            for (int i = index; i < *len - 1; i++)
            {
                (*array)[i] = (*array)[i + 1];
            }
            *len = (*len) - 1;
            *array = (int*) realloc(*array, (*len) * sizeof(int));
        }
        else
        {
            std::cout << "Данного индекса не существует" << std::endl;
        }

    }
}

void arrayBinarySort(int** array, int len)
{
    if (array == NULL)
    {
        std::cout << "Проинициализируйте пожалуйста массив" << std::endl;
    }
    else
    {
        int i   = 0;
        int j   = 0;
        int key = 0;
        for (i = 1; i < len; i++) {
            key = (*array)[i];
            j = i - 1;
            while (j >= 0 && (*array)[j] > key) {
                (*array)[j + 1] = (*array)[j];
                j = j - 1;
            }
            (*array)[j + 1] = key;
        }
    }
}

void arrayReverse(int** array, int len)
{
    if (array == NULL)
    {
        std::cout << "Массива не существует" << std::endl;
    }
    else
    {
        int* arrayR = (int*)malloc(len * sizeof(int));

        for (int i = 0; i < len; i++)
        {
            arrayR[i] = (*array)[len - 1 - i];
        }

        free(*array);
        (*array) = arrayR;
    }
}

void arraySwitch(int** array, int len)
{
    if (*array == NULL)
    {
        std::cout << "Массив пустой" << std::endl;
    }
    else
    {
        int maxInt = (*array)[0];
        int minInt = (*array)[0];
        int maxInd = 0;
        int minInd = 0;

        for (int i = 0; i < len; i++)
        {
            if (maxInt <= (*array)[i])
            {
                maxInt = (*array)[i];
                maxInd = i;
            }
            if (minInt > (*array)[i])
            {
                minInt = (*array)[i];
                minInd = i;
            }
        }
        (*array)[maxInd] = minInt;
        (*array)[minInd] = maxInt;
    }
}

void arrayDeleteDuplicate(int** array, int* len)
{
    if (array == NULL)
    {
        std::cout << "Массива не существует" << std::endl;
    }
    else
    {
        int* arrayND    = (int*) malloc((*len) * sizeof(int));
        int duplicate   = 0;
        int size        = 0;
        for (int i = 0; i < *len; i++)
        {
            duplicate = 0;

            for (int j = 0; j < size; j++)
            {
                if ((*array)[i] == arrayND[j])
                {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate == 0)
            {
                arrayND[size] = (*array)[i];
                size++;
            }
        }
        free(*array);
        *len = size;
        (*array) = arrayND;
    }
}

