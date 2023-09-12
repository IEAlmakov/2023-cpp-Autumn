#include <iostream>

#define ALWAYS_NINE 9

int main() {
    int k = 0;
    std::cin >> k;
    std::cout << k << ALWAYS_NINE << ALWAYS_NINE - k << std::endl;
    return 0;
}