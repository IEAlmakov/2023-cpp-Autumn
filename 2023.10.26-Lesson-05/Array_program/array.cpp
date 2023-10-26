#include "array.h"
#include "helper.h"

void arrayInitialization (int*& array, int& len) {
    for (int i = 0; i < len; i++)
    {
        std::cout << "Введите элемент массива" << std::endl;
        correct(&(array[i]));
        std::cout << std::endl;
    }
}

void arrayCreate(int*& array, int& len)
{
    if (array == nullptr)
    {
        array = (int*) malloc(sizeof(int));

        if (array == nullptr)
        {
            std::cout << "Массив не удалось создать, попробуйте перезапустить программу" << std::endl;
        }
        len = 1;
    }
    else
    {
        len++;
        array = (int*) realloc(array, len * sizeof(int));
    }
}

void arrayAdd(int*& array, int& len, int index, int element)
{
    if (array == nullptr)
    {
        arrayCreate(array, len);
        array[0] = element;
    }
    else
    {
        if (index < len)
        {
            array[index] = element;
        }
        else
        {
            arrayCreate(array, len);
            array[len-1] = element;
        }
    }
}

void arrayDelete (int*& array, int& len, int index)
{
    if (array == nullptr)
    {
        std::cout << "Массива не существует" << std::endl;
    }

    else {

        if (index < len)
        {
            for (int i = index; i < len - 1; i++)
            {
                (array)[i] = (array)[i + 1];
            }
            len = (len) - 1;
            array = (int*) realloc(array, (len) * sizeof(int));
        }
        else
        {
            std::cout << "Данного индекса не существует" << std::endl;
        }

    }
}

void arrayBinarySort(int*& array, int len)
{
    if (array == nullptr)
    {
        std::cout << "Проинициализируйте пожалуйста массив" << std::endl;
    }
    else
    {
        int i   = 0;
        int j   = 0;
        int key = 0;

        for (i = 1; i < len; i++) {
            key = (array)[i];
            j = i - 1;

            while (j >= 0 && (array)[j] > key) {
                (array)[j + 1] = (array)[j];
                j = j - 1;
            }

            (array)[j + 1] = key;
        }
    }
}

void arrayReverse(int*& array, int len)
{

    if (array == nullptr)
    {
        std::cout << "Массива не существует" << std::endl;
    }
    else
    {
        int* arrayR = (int*)malloc(len * sizeof(int));

        for (int i = 0; i < len; i++)
        {
            arrayR[i] = (array)[len - 1 - i];
        }

        free(array);
        (array) = arrayR;
    }

}

void arraySwitch(int *&array, int len)
{
    if (array == nullptr)
    {
        std::cout << "Массив пустой" << std::endl;
    }
    else
    {
        int maxInt = (array)[0];
        int minInt = (array)[0];
        int maxInd = 0;
        int minInd = 0;

        for (int i = 0; i < len; i++)
        {
            if (maxInt <= (array)[i])
            {
                maxInt = (array)[i];
                maxInd = i;
            }
            if (minInt > (array)[i])
            {
                minInt = (array)[i];
                minInd = i;
            }
        }
        (array)[maxInd] = minInt;
        (array)[minInd] = maxInt;
    }
}

void arrayDeleteDuplicate(int*& array, int& len)
{
    if (array == NULL)
    {
        std::cout << "Массива не существует" << std::endl;
    }
    else
    {
        int* arrayND    = (int*) malloc((len) * sizeof(int));
        int duplicate   = 0;
        int size        = 0;
        for (int i = 0; i < len; i++)
        {
            duplicate = 0;

            for (int j = 0; j < size; j++)
            {
                if ((array)[i] == arrayND[j])
                {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate == 0)
            {
                arrayND[size] = (array)[i];
                size++;
            }
        }
        free(array);
        len = size;
        (array) = arrayND;
    }
}

void arrayRandom(int*& array, int& len, int n)
{
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        int randomElement = 2147483647;
        while (randomElement >= 2147483647)
        {
            randomElement = rand();
            arrayAdd(array, len, len, randomElement);
        }
        std::cout << randomElement << std::endl;
    }
}
