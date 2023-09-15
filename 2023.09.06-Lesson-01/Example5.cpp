#include <iostream>

int main() {
    int V = 0;
    int T = 0;
    int rest = 0;
    int distance = 0;
    int highway = 109;
    std::cin >> V >> T;
    rest = (V * T) % highway;
    distance = (highway + rest) % highway + 1;
    std::cout << distance << std::endl;
    return 0;
}