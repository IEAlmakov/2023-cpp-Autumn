#include "graph.h"

int main(int argc, char *argv[])
{
    Graph graph;
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    graph.createAdjacencyList(n, m);

    return EXIT_SUCCESS;
}
