#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int n = 0;
    int rem = 0;
    int gcd = 0;
    char a_name = 'A';
    char b_name = 'B';
    
    std::cin >> a;
    std::cin >> b;
    std::cin >> n;
    
    int a1 = a;
    int b1 = b;

    if (a > b)
    {
        gcd = a;
        a = b;
        b = gcd;
        a_name = 'B';
        b_name = 'A';
    }

    if (n == b)
    {
        std::cout << ">" << b_name;
        return 0;
    }
    
    while (b1 != 0) 
    {
        gcd = a1 % b1;
        a1 = b1;
        b1 = gcd;
    }
    if ((n % a1 != 0) || ((n > a) && (n > b)))
    {
        std::cout << "Impossible" << std::endl;
    }
    else
    {
        while (1 > 0)
        {
            rem += a;
            std::cout << ">" << a_name << std::endl;
            std::cout << a_name << ">" << b_name << std::endl;
            if (rem >= b)
            {
                std::cout << b_name << ">" << std::endl;
                std::cout << a_name << ">" << b_name << std::endl;
                rem %= b;
            }
            if ((rem == n) || (rem == 0))
            {
                break;
            }
        }
    }
    return EXIT_SUCCESS;
}