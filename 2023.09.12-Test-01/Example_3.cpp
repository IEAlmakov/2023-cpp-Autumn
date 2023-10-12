#include <iostream>

int main(int argc, char* argv[]) {
    int n = 0;
    std::cin >> n;
    
    while (n > 0) 
    {
        std::cout << n % 10;
        n /= 10;
    }
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}
