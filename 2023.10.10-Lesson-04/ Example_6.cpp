#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) 
{
    int size = 0;
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

    int max_el  = *array;
    int min_el  = *array;
    int max_ind = 0;
    int min_ind = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) >= max_el) 
        {
            max_el = *(array + i);
            max_ind = i;
        }
        if (*(array + i) < min_el) 
        {
            min_el = *(array + i);
            min_ind = i;
        }
    }
    *(array + min_ind) = max_el;
    *(array + max_ind) = min_el;

    std::cout << "Элементы массива: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;

    free(array);

    return EXIT_SUCCESS;
}