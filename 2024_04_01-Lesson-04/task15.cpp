#include "graph.h"

int main(int argc, char *argv[])
{
    int n, m;
    std::cin >> n >> m;

    Graph graph;
    graph.readEdges(m);

    if (graph.isTournament(n, m))
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
    return EXIT_SUCCESS;
}
