#include <iostream>

#define HIGHWAY 109 

int distance (int V, int T) {
    int rest = 0;
    int distance = 0;
    rest = (V * T) % HIGHWAY;
    distance = (HIGHWAY + rest) % HIGHWAY + 1;
    return distance;
}

int main() {
    int V = 0;
    int T = 0;
    std::cin >> V >> T;
    V = distance (V, T);
    std::cout << V << std::endl;
    return 0;
}