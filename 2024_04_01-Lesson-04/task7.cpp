#include "graph.h"

int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;

    Graph graph;
    graph.readMatrix(n);
    graph.initEdgesFromMatrixOfVertexes();
    int m = 0;
    m = graph.getEdgesCountFromMatrix();
    std::cout << n << " " << m << std::endl;
    graph.printEdges();
    return EXIT_SUCCESS;
}
