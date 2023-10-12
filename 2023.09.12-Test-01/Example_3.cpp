#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) 
{
    int n = 0;
    std::cin >> n;

    if (n >= 0) 
    {
        for (int i = 0; i <= n; ++i) 
        {
            std::cout << i << " ";
        }
    } 
    else 
    {
        for (int i = 0; i >= n; --i) 
        {
            std::cout << i << " ";
        }
    }
    
    for (int i = std::abs(n) - 1; i >= 0; --i) 
    {
        std::cout << ((n > 0) ? i : -i) << " ";
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}
