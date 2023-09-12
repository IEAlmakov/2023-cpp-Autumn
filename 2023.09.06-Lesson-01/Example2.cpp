#include <iostream>
#include <math.h>

int our_sum(int an) {
    int d = (abs(an - 1))/(an - 1);
    int n = 1 + ((an - 1)/ d);
    int s = (1 + an) * n / 2;
    return s;
}

int main() {
    int a_n = 0;
    std::cin >> a_n;
    a_n = our_sum(a_n);
    std::cout << a_n << std::endl;
    return 0;
}