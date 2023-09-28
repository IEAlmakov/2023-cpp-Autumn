#include <iostream>

int main(int argc, char* argv[]) 
{
    int a = 0;
    std::cin >> a;
    int k = a;
    
    for (int i = 1; i <= a; i++) 
    {
        for (int j = 1; j <= i && k > 0; j++) 
        {
            std::cout << i << " ";
            k--;
        }
    }
    
    std::cout << std::endl;
    return EXIT_SUCCESS;
}