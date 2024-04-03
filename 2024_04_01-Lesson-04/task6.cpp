#include "graph.h"

int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;

    Graph graph(n - 1, n);
    graph.readEdges(n - 1);

    int importantPlanets = graph.specialPlanet();

    std::cout << importantPlanets << std::endl;

    return EXIT_SUCCESS;
}
