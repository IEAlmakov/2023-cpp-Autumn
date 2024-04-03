#include "graph.h"

int main(int argc, char *argv[])
{
    Graph graph;

    int n = 0;
    long long a = 0;
    long long b = 0;

    std::cin >> n;
    std::cin >> a;
    std::cin >> b;

    long long result = graph.ourMommy(a, b);
    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}
