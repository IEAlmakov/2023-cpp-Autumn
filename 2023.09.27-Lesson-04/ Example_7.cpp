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

    std::cout << "Размер массива до основного процесса программы: " <<  sizeof(array) * size / sizeof(*array) << std::endl;
    int count = 0;
    int index = 0;
    int* temp_array = (int*) malloc(count * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) > 0) 
        {
            count++;
            temp_array = (int*) realloc(temp_array, count * sizeof(int));
            *(temp_array + index) = *(array + i);
            index++;
        }
    }
    size = count;
    free(array);
    array = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        *(array + i) = *(temp_array + i);
    }
    free(temp_array);
    std::cout << "Размер массива после основного процесса программы: " <<  sizeof(array) * size / sizeof(*array) << std::endl;

    std::cout << "Элементы массива: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;

    free(array);

    return EXIT_SUCCESS;
}