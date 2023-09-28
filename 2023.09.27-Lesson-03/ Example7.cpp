#include <iostream>

int main(int argc, char* argv[]) 
{
    int n = 0;
    int k = 1;
    int count = 0;
    
    std::cin >> n;
    
    while (k < n) 
    {
        k *= 2;
        count += 1;
    }
    
    std::cout << count << std::endl;
    return EXIT_SUCCESS;
}