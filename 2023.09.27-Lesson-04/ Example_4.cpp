#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) 
{
    int size    = 0;
    int max_el  = 0;
    
    std::cout << "Введите пожалуйста размер массива: ";
    std::cin >> size;
    std::cout << std::endl;

    int* array = (int*) malloc(size * sizeof(int));
    if (array == NULL) 
    {
        std::cout << "В ходе инициализации массива произошла ошибка, попробуйте позже" << std::endl;
        free(array);
        return EXIT_FAILURE;
    }
    
    std::cout << "Введите элементы: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> *(array + i);
    }
    std::cout << std::endl;

    max_el = *array;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) > max_el) 
        {
            max_el = *(array + i);
        }
    }
    std::cout << "Максимальнй элемент: " << max_el << std::endl;

    free(array);

    return EXIT_SUCCESS;
}