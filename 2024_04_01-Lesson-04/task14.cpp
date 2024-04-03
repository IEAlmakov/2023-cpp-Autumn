#include <iostream>

class Graph
{
private:
    int N;
    static const int MAX = 100;
    int adjacencyMatrix[MAX][MAX];

public:
    void readGraph();
    void findSourcesAndDrains();
};

void Graph::readGraph()
{
    std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> adjacencyMatrix[i][j];
        }
    }
}

void Graph::findSourcesAndDrains()
{
    int sources[MAX], drains[MAX];
    int sourcesCount = 0;
    int drainsCount = 0;

    for (int i = 0; i < N; ++i)
    {
        bool isSource = true;
        bool isDrain = true;

        for (int j = 0; j < N; ++j)
        {
            if (adjacencyMatrix[j][i] != 0)
            {
                isSource = false;
            }
            if (adjacencyMatrix[i][j] != 0)
            {
                isDrain = false;
            }
        }

        if (isSource)
        {
            sources[sourcesCount++] = i + 1;
        }

        if (isDrain)
        {
            drains[drainsCount++] = i + 1;
        }
    }

    std::cout << sourcesCount << " ";
    for (int i = 0; i < sourcesCount; ++i)
    {
        std::cout << sources[i] << " ";
    }
    std::cout << std::endl;

    std::cout << drainsCount << " ";
    for (int i = 0; i < drainsCount; ++i)
    {
        std::cout << drains[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    Graph graph;
    graph.readGraph();
    graph.findSourcesAndDrains();

    return EXIT_SUCCESS;
}
