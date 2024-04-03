#include "graph.h"

int main(int argc, char *argv[])
{
    Graph graph;
    int n = 0;
    int m = 0;

    std::cin >> n;
    graph.readMatrix(n);
    graph.readRGBRoads(n);

    std::cout << graph.countWrongRGBRoads() << std::endl;
    return EXIT_SUCCESS;
}
