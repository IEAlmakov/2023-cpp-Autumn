#include "graph.h"

int main(int argc, char *argv[])
{
    Graph graph;

    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    graph.readEdges(m);
    graph.initMatrixFromEdges();

    if (graph.completeGraph() == 1)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    return EXIT_SUCCESS;
}
