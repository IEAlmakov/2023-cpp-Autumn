#include <iostream>

int main(int argc, char* argv[]) 
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;

    for (int i = 0; i <= 1000; i++) 
    {
        if ((i * (a * i * i + b * i + c) + d) == 0) 
        {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}