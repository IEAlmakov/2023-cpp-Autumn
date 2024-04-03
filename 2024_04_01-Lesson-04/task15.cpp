#include <iostream>

class Graph
{
private:
    int **adjacencyMatrix;
    int n;

public:
    Graph(int size) : n(size)
    {
        adjacencyMatrix = new int *[n];
        for (int i = 0; i < n; ++i)
        {
            adjacencyMatrix[i] = new int[n];
            for (int j = 0; j < n; ++j)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int from, int to)
    {
        adjacencyMatrix[from - 1][to - 1] = 1;
    }

    bool isTournament(int m)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    if (!(adjacencyMatrix[i][j] ^ adjacencyMatrix[j][i]))
                    {
                        return false;
                    }
                }
            }
        }

        if (m != n * (n - 1) / 2)
        {
            return false;
        }

        return true;
    }

    ~Graph()
    {
        for (int i = 0; i < n; ++i)
        {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }
};

int main(int argc, char *argv[])
{
    int n, m;
    std::cin >> n >> m;

    Graph tournament(n);

    for (int i = 0; i < m; ++i)
    {
        int from, to;
        std::cin >> from >> to;
        tournament.addEdge(from, to);
    }

    if (tournament.isTournament(m))
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    return EXIT_SUCCESS;
}
