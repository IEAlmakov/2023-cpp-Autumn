#include "graph.h"

int main(int argc, char *argv[])
{
    Graph graph;

    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    graph.readEdges(m);
    if (graph.orientedGraph() == 1)
    {
        std::cout << "NO";
    }
    else
    {
        std::cout << "YES";
    }

    return EXIT_SUCCESS;
}
