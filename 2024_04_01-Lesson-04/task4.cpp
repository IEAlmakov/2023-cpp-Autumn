#include "graph.h"

int main(int argc, char *argv[])
{
    Graph graph;
    int n = 0;
    int m = 0;

    std::cin >> n;
    graph.readMatrix(n);
    m = graph.algorithmFloydWarshall();
    std::cout << m;

    return EXIT_SUCCESS;
}
