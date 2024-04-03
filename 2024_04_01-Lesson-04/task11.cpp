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
    int *degrees;

public:
    Graph() : n(0), matrix(nullptr), degrees(nullptr)
    {
    }

    ~Graph()
    {
        delete[] degrees;

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
    void findDegrees();
    void graphRegular();
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

void Graph::findDegrees()
{
    degrees = new int[n]();

    for (int i = 0; i < n; ++i)
    {
        int count = 0;
        for (int j = 0; j < n; ++j)
        {
            count += matrix[i][j];
        }
        degrees[i] = count;
    }
}

void Graph::graphRegular()
{
    if (degrees == nullptr)
    {
        findDegrees();
    }

    for (int i = 1; i < n; ++i)
    {
        if (degrees[i] != degrees[0])
        {
            std::cout << "NO" << std::endl;
            return;
        }
    }

    std::cout << "YES" << std::endl;
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
        graphRegular();
    }
};

int main(int argc, char *argv[])
{
    GraphSolver graphSolver;
    graphSolver.solve();

    return EXIT_SUCCESS;
}
