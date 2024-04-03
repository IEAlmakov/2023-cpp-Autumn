#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr)
    {
    }
};

class Graph
{
protected:
    int n;
    int **matrix;

public:
    Graph() : n(0), matrix(nullptr)
    {
    }

    ~Graph()
    {
        if (matrix != nullptr)
        {
            for (int i = 0; i < n; ++i)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    }

    void createAdjacencyMatrix();
    void graphOriented();
};

void Graph::createAdjacencyMatrix()
{
    std::cin >> n;
    matrix = new int *[n];

    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void Graph::graphOriented()
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] != 0)
        {
            std::cout << "NO" << std::endl;
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (matrix[i][j] != matrix[j][i] && matrix[i][j] != 0)
            {
                std::cout << "YES" << std::endl;
                return;
            }
        }
    }

    std::cout << "NO" << std::endl;
}

class GraphSolver : public Graph
{
public:
    GraphSolver() : Graph()
    {
    }

    void solve()
    {
        createAdjacencyMatrix();
        graphOriented();
    }
};

int main(int argc, char *argv[])
{
    GraphSolver graphSolver;
    graphSolver.solve();

    return EXIT_SUCCESS;
}
