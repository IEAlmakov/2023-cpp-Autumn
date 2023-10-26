#include "correct.h"

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
