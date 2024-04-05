#include "graph.h"

int main(int argc, char *argv[])
{
    Graph graph;

    int n = 0;
    std::cin >> n;

    graph.readMatrix(n);
    graph.sourcesdrains();
    return EXIT_SUCCESS;
}
