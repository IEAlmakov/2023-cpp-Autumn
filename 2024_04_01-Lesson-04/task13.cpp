#include <iostream>

class GraphSolver
{
private:
    int edges[10000][2];
    int n, m;

public:
    void readGraph();
    bool isCompleteGraph();
};

void GraphSolver::readGraph()
{
    std::cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        std::cin >> edges[i][0] >> edges[i][1];
    }
}

bool GraphSolver::isCompleteGraph()
{
    bool adjMatrix[100][100] = {false};

    for (int i = 0; i < m; ++i)
    {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        adjMatrix[u][v] = adjMatrix[v][u] = true;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (!adjMatrix[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    GraphSolver graphSolver;
    graphSolver.readGraph();

    if (graphSolver.isCompleteGraph())
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    return EXIT_SUCCESS;
}
