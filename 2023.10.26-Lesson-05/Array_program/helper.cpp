#include "helper.h"

//Проверка, что пользовать ввел именно число, а не букву например.
void correct(int* checkNumber)
{
    int enterNumber = scanf("%d", checkNumber);
    while (enterNumber == 0)
    {
        std::cout << "Введите другое число" << std::endl;
        scanf("%*[^\n]");
        enterNumber = scanf("%d", checkNumber);
    }
}

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

int indexCheck(int index)
{
    std::cout << "Введите индекс элемента массива" << std::endl;
    std::cout << "!!!! Индекс элемента >= 0 !!!!!" << std::endl;
    index = -1;
    while (index < 0)
    {
        correct(&index);
    }
    return index;
}

int elementCheck(int element)
{
    element = 0;
    std::cout << "Введите элемент массива" << std::endl;
    correct(&element);
    return element;
}
