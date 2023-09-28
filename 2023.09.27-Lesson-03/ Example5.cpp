#include <iostream>

int main(int argc, char* argv[]) 
{
    int k = 0;
    int count = 0;
    std::cin >> k;
    
    for (int i = 1; i <= k; i++) 
    {
        int j = i;
        int p = 0;
        while (j > 0) {
            p = j % 10 + p * 10;
            j = j / 10;
        }
        if (p == i) {
            count += 1;
        }
    }

    std::cout << count << std::endl;
    return EXIT_SUCCESS;
}