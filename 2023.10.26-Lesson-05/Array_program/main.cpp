#include <iostream>

#include "correct.h"
#include "array.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    int *array  = NULL;
    int len     = 0;
    bool exit   = false;

    while (!exit)
    {
        //system("cls");
        //printMenu();
        std::cout << std::endl;
        arrayPrint (array, len);

        int option  = 0;
        correct(&option);

        switch (option)
        {
        case 1:
            exit = true;
            break;
        case 2:
            arrayPrint (array, len);
            break;
        case 3:
            arrayAdd(&array, &len);
            break;
        case 4:
            arrayDelete(&array, &len);
            break;
        case 5:
            arrayBinarySort(&array, len);
            break;
        case 6:
            arrayReverse(&array, len);
            break;
        case 7:
            arraySwitch(&array, len);
            break;
        case 8:
            arrayDeleteDuplicate(&array, &len);
            break;
        case 9:
            arrayCreate(&array, &len);
            break;
        default:
            std::cout << "Введите пожалуйста другую опцию" << std::endl;
            break;
        }
    }

    free(array);

    return EXIT_SUCCESS;
}
