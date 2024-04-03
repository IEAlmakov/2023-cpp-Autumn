#include "graph.h"

int main(int argc, char *argv[])
{
    Graph graph;
    int n = 0;
    int count = 0;
    std::cin >> n;
    graph.readMatrix(n);
    std::cout << graph.countRoads() << std::endl;
    return EXIT_SUCCESS;
}
