#include "graph.h"

int main(int argc, char *argv[])
{
    Graph graph;

    int n = 0;
    std::cin >> n;

    graph.readMatrix(n);
    if (graph.regularGraph() == 1)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }

    return EXIT_SUCCESS;
}
