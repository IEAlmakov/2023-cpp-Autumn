#include <iostream>

#include "helper.h"
#include "array.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    int *array  = nullptr;
    int len     = 0;
    bool exit   = false;

    while (!exit)
    {
        system("clear");
        printMenu();
        std::cout << std::endl;
        int option  = 0;
        correct(&option);

        int index = 0;
        int element = 0;
        int n = 0;

        switch (option)
        {
            case 1:
                exit = true;
                break;
            case 2:
                arrayPrint (array, len);
                std::cout << "Для продолжения нажмите любую клавишу" << std::endl;
                system("read");
                break;
            case 3:
                index = indexCheck(index);
                element = elementCheck(element);
                arrayAdd(array, len, index, element);
                break;
            case 4:
                index = indexCheck(index);
                arrayDelete(array, len, index);
                break;
            case 5:
                arrayBinarySort(array, len);
                break;
            case 6:
                arrayReverse(array, len);
                break;
            case 7:
                arraySwitch(array, len);
                break;
            case 8:
                arrayDeleteDuplicate(array, len);
                break;
            case 9:
                std::cout << "Введите пожалуйста количество элементов" << std::endl;
                correct(&n);
                arrayRandom(array, len, n);
                break;
            default:
                std::cout << "Введите пожалуйста другую опцию" << std::endl;
                break;
        }
    }
    free(array);

    return EXIT_SUCCESS;
}
