#include <iostream>
#include <math.h>

int main() {
    int a_n = 0;
    std::cin >> a_n;
    int d = (abs(a_n - 1))/(a_n - 1);
    int n = 1 + ((a_n - 1)/ d);
    int s = (1 + a_n) * n / 2;
    std::cout << a_n << std::endl;
    return 0;
}