#include <iostream>

int main(int argc, char* argv[]) 
{
    int x = 0;
    int y = 0;
    
    std::cin >> x;
    
    while (x > 0) 
    {
        y = y * 10 + (x % 10);
        x = x / 10;
    }

    std::cout << y << std::endl;
    return EXIT_SUCCESS;
}