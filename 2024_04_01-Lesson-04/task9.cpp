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
    Node **adjList;

public:
    Graph() : n(0), adjList(nullptr)
    {
    }

    ~Graph()
    {
        if (adjList != nullptr)
        {
            for (int i = 0; i < n; ++i)
            {
                Node *curr = adjList[i];
                while (curr != nullptr)
                {
                    Node *temp = curr;
                    curr = curr->next;
                    delete temp;
                }
            }
            delete[] adjList;
        }
    }

    void createAdjacencyList(int vertices);
};

void Graph::createAdjacencyList(int vertices)
{
    n = vertices;
    adjList = new Node *[n]();

    for (int i = 0; i < n; ++i)
    {
        int neighbors;
        std::cin >> neighbors;

        for (int j = 0; j < neighbors; ++j)
        {
            int neighborVertex;
            std::cin >> neighborVertex;
            Node *newNode =
                new Node(neighborVertex - 1); // Учитывая, что номера вершин начинаются с 1, а индексация с 0
            newNode->next = adjList[i];
            adjList[i] = newNode;
        }
    }
}

class GraphSolver : public Graph
{
public:
    GraphSolver() : Graph()
    {
    }

    void createAdjacencyMatrix();
};

void GraphSolver::createAdjacencyMatrix()
{
    std::cout << n << std::endl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int isAdjacent = 0;
            Node *curr = adjList[i];
            while (curr != nullptr)
            {
                if (curr->data == j)
                {
                    isAdjacent = 1;
                    break;
                }
                curr = curr->next;
            }
            std::cout << isAdjacent << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[])
{
    GraphSolver graphSolver;

    int N;
    std::cin >> N;

    graphSolver.createAdjacencyList(N);
    graphSolver.createAdjacencyMatrix();

    return EXIT_SUCCESS;
}
