#include "graph.h"

int main(int argc, char *argv[])
{
    Graph graph;

    int n = 0;
    std::cin >> n;

    graph.createAdjacencyMatrix(n);

    return EXIT_SUCCESS;
}
