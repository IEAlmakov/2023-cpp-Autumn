#include "graph.h"

std::ostream &operator<<(std::ostream &stream, const SEdge &edge)
{
    stream << edge.from << " " << edge.to;
    if (edge.weight > 1)
    {
        stream << " " << edge.weight;
    }
    return stream;
}
 
void Edge::initEdges()
{
    disposeEdges();
    if (_edges == 0)
    {
        return;
    }
    _edge = new SEdge[_edges];
}
 
void Edge::disposeEdges()
{
    if (_edge != nullptr)
    {
        delete[] _edge;
        _edge = nullptr;
    }
}
 
void Edge::readEdges(int edges, bool haveweight)
{
    _edges = edges;
    initEdges();
    for (int i = 0; i < _edges; ++i)
    {
        std::cin >> _edge[i].from >> _edge[i].to;
        if (haveweight)
        {
            std::cin >> _edge[i].weight;
        }
    }
}
 
int Edge::getVertexesCountFromEdges()
{
    int res = INT_MIN;
    for (int i = 0; i < _edges; ++i)
    {
        res = (res > _edge[i].from) ? ((res > _edge[i].to) ? res : _edge[i].to)
                                    : ((_edge[i].from > _edge[i].to) ? _edge[i].from : _edge[i].to);
    }
    return res + 1;
}
 
void Edge::listCrossing(int roads, int tunnels)
{
    int *_list = new int[roads]{};
    for (int i = 0; i < tunnels; ++i)
    {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        _list[a - 1] += 1;
        _list[b - 1] += 1;
    }
    for (int i = 0; i < roads; ++i)
    {
        std::cout << _list[i] << " ";
    }
    delete[] _list;
}
 
int Edge::specialPlanet()
{
    int maxPlanet = -1;
    for (int i = 0; i < _edges; ++i)
    {
        maxPlanet = (maxPlanet > _edge[i].from) ? maxPlanet : _edge[i].from;
        maxPlanet = (maxPlanet > _edge[i].to) ? maxPlanet : _edge[i].to;
    }
 
    int *count = new int[maxPlanet + 1]();
 
    for (int i = 0; i < _edges; ++i)
    {
        count[_edge[i].from]++;
        count[_edge[i].to]++;
    }
 
    int importantPlanets = 0;
 
    for (int i = 1; i <= maxPlanet; ++i)
    {
        if (count[i] > 1)
        {
            importantPlanets++;
        }
    }
 
    delete[] count;
 
    return importantPlanets;
}
 
void Vertex::initMatrix()
{
    disposeMatrix();
    if (_vertexes == 0)
    {
        return;
    }
    _matrixFromVertexes = new int *[_vertexes];
    for (int i = 0; i < _vertexes; ++i)
    {
        _matrixFromVertexes[i] = new int[_vertexes]{0};
    }
}
 
void Vertex::disposeMatrix()
{
    if (_matrixFromVertexes != nullptr)
    {
        for (int i = 0; i < _vertexes; ++i)
        {
            delete[] _matrixFromVertexes[i];
        }
        delete[] _matrixFromVertexes;
        _matrixFromVertexes = nullptr;
    }
}
 
void Vertex::readRGBRoads(int countOfRGBRoads)
{
    _countOfRGBRoads = countOfRGBRoads;
    initRGBRoads();
    for (int i = 0; i < _countOfRGBRoads; ++i)
    {
        std::cin >> _rgbRoads[i];
    }
}
 
void Vertex::colorMatrix()
{
    for (int i = 0, k = 0; i < _countOfRGBRoads; ++i, ++k)
    {
        for (int j = 0; j < _countOfRGBRoads; ++j)
        {
            _matrixFromVertexes[j][i] = _rgbRoads[k] * _matrixFromVertexes[j][i];
        }
    }
}
 
int Vertex::algorithmFloydWarshall()
{
    int minDist = INT_MAX;
 
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            for (int k = 0; k < _vertexes; ++k)
            {
                if (i != j && j != k && k != i)
                {
                    int dist = _matrixFromVertexes[i][j] + _matrixFromVertexes[j][k] + _matrixFromVertexes[k][i];
                    if (dist < minDist)
                    {
                        minDist = dist;
                    }
                }
            }
        }
    }
 
    return minDist;
}
 
int Vertex::countWrongRGBRoads()
{
    int count = 0;
    colorMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            if (_matrixFromVertexes[i][j] != 0 && (_matrixFromVertexes[i][j] != _matrixFromVertexes[j][i]))
            {
                count++;
            }
        }
    }
    return (count / 2);
}
 
void Vertex::initRGBRoads()
{
    disposeRGBRoads();
    _rgbRoads = new int[_countOfRGBRoads];
}
 
void Vertex::disposeRGBRoads()
{
    if (_rgbRoads != nullptr)
    {
        delete[] _rgbRoads;
        _rgbRoads = nullptr;
    }
}
 
void Vertex::readMatrix(int vertexes)
{
    _vertexes = vertexes;
    initMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            std::cin >> _matrixFromVertexes[i][j];
        }
    }
}
 
int Vertex::getEdgesCountFromMatrix()
{
    int count = 0;
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            count += (_matrixFromVertexes[i][j] != 0);
        }
    }
    return count;
}
 
int Vertex::countRoads()
{
    int count = 0;
    int k = 0;
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            count += (_matrixFromVertexes[i][j] != 0);
        }
        k++;
    }
    return count;
}
 
void Graph::init()
{
    initMatrix();
    initEdges();
}
 
void Graph::dispose()
{
    disposeMatrix();
    disposeEdges();
}
 
void Graph::printEdges()
{
    if (_edge == nullptr)
    {
        if (_matrixFromVertexes == nullptr)
        {
            std::cout << "Graph empty" << std::endl;
            return;
        }
        initEdgesFromMatrixOfVertexes();
    }
    for (int i = 0; i < _edges; ++i)
    {
        std::cout << _edge[i] << std::endl;
    }
}
 
void Graph::initMatrixFromEdges()
{
    disposeMatrix();
    _vertexes = getVertexesCountFromEdges();
    initMatrix();
 
    if (_matrixFromVertexes == nullptr)
    {
        _matrixFromVertexes = new int *[_vertexes];
        for (int i = 0; i < _vertexes; ++i)
        {
            _matrixFromVertexes[i] = new int[_vertexes]();
        }
    }
 
    for (int i = 0; i < _edges; ++i)
    {
        _matrixFromVertexes[_edge[i].from][_edge[i].to] = _edge[i].weight;
    }
}
 
void Graph::initEdgesFromMatrixOfVertexes()
{
    disposeEdges();
    _edges = getEdgesCountFromMatrix();
    initEdges();
    for (int i = 0, k = 0; i < _vertexes && k < _edges; ++i)
    {
        for (int j = 0; j < _vertexes && k < _edges; ++j)
        {
            if (_matrixFromVertexes[i][j] != 0)
            {
                _edge[k++].set(i + 1, j + 1, _matrixFromVertexes[i][j]);
            }
        }
    }
}
 
void Graph::printMatrix()
{
    if (_matrixFromVertexes == nullptr)
    {
        if (_edge == nullptr)
        {
            std::cout << "Graph empty" << std::endl;
            return;
        }
        initMatrixFromEdges();
    }
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            std::cout << _matrixFromVertexes[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
 
long long Graph::ourMommy(long long children_1, long long children_2)
{
    while (children_1 != children_2)
    {
        if (children_1 > children_2)
        {
            children_1 /= 2;
        }
        else
        {
            children_2 /= 2;
        }
    }
    return children_1;
}

void Graph::createAdjacencyList(int n, int m)
{
    int **v = new int *[n];
    int *cnt = new int[n]();

    for (int i = 0; i < n; ++i)
    {
        v[i] = new int[n]();
    }

    int a, b;

    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        v[a - 1][cnt[a - 1]++] = b - 1;
    }

    std::cout << n << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << cnt[i] << " ";
        for (int j = 0; j < cnt[i]; j++)
        {
            int minValue = j;
            for (int k = j + 1; k < cnt[i]; k++)
            {
                if (v[i][k] < v[i][minValue])
                {
                    std::swap(v[i][k], v[i][minValue]);
                }
            }
            std::cout << v[i][j] + 1 << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i)
    {
        delete[] v[i];
    }
    delete[] v;
    delete[] cnt;
}

void GraphSolver::resizeArrays()
{
    adjList = new Node *[n + 1];
    parent = new int[n + 1]();
    for (int i = 0; i <= n; i++)
    {
        adjList[i] = nullptr;
    }
}

void GraphSolver::dfs(int i, int p)
{
    parent[i] = p;
    Node *curr = adjList[i];
    while (curr != nullptr)
    {
        if (parent[curr->data] == 0)
        {
            dfs(curr->data, i);
        }
        curr = curr->next;
    }
}

int GraphSolver::findCommonAncestor(int u, int v)
{
    while (u != v)
    {
        if (u > v)
        {
            u = parent[u];
        }
        else
        {
            v = parent[v];
        }
    }
    return u;
}

void GraphSolver::addEdge(int from, int to)
{
    Node *newNode = new Node(to);
    newNode->next = adjList[from];
    adjList[from] = newNode;
}

void GraphSolver::setInput()
{
    int tmp;
    std::cin >> n >> monitor1 >> monitor2;

    resizeArrays();

    for (int i = 2; i <= n; i++)
    {
        std::cin >> tmp;
        addEdge(tmp, i);
    }
}

void GraphSolver::solveGraph()
{
    dfs(1, 0);
    int commonAncestor = findCommonAncestor(monitor1, monitor2);
    std::cout << commonAncestor;
}
