#include <iostream>

int main(int argc, char* argv[]) 
{
    int x = 0;
    int k = 0;
    int m = 0;
    int n = 0;
    
    std::cin >> x;

    int i = 1;
    while (i <= x) 
    {
        if (i * i >= x) 
        {
            m = i;
            break;
        }
        i++;
    }

    i = 1;
    while (i <= m) 
    {
        if (x % i == 0) 
        {
            k += 2;
        }
        i++;
    }

    if (x % m == 0) 
    {
        k--;
    }

    std::cout << k << std::endl;
    return EXIT_SUCCESS;
}