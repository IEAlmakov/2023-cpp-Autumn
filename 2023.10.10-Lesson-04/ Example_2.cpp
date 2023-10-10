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

    std::cout << "Элементы массива на четных местах: " << std::endl;
    for (int i = 0; i < size; i += 2)
    {
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;

    free(array);

    return EXIT_SUCCESS;
}