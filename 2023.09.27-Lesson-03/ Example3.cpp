#include <iostream>

int main(int argc, char* argv[]) 
{
    int x = 0;
    int k = 0;
    int m = 0;
    int n = 0;
    
    std::cin >> x;

    for (int i = 1; i <= x; i++) 
    {
        if (i * i >= x) 
        {
            m = i;
            break;
        }
    }

    for (int i = 1; i <= m; i++) 
    {
        if (x % i == 0) 
        {
            k += 2;
        }
    }

    if (x % m == 0) 
    {
        k--;
    }

    std::cout << k << std::endl;
    return EXIT_SUCCESS;
}