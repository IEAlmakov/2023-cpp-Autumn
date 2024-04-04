#ifndef GRAPH_H
#include <iostream>
#define GRAPH_H

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr)
    {
    }
};

struct SEdge
{
    int from;
    int to;
    int weight;

    SEdge(int from = 0, int to = 0, int weight = 1) : from(from), to(to), weight(weight)
    {
    }

    SEdge(const SEdge &cpy) : from(cpy.from), to(cpy.to), weight(cpy.weight)
    {
    }

    ~SEdge()
    {
    }

    void set(int from, int to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }

    friend std::ostream &operator<<(std::ostream &stream, const SEdge &edge);
};

class Edge
{
public:
    Edge() : _edges(0), _edge(nullptr)
    {
    }
    Edge(int edges) : _edges(edges), _edge(nullptr)
    {
    }

    ~Edge()
    {
        disposeEdges();
    }

    void readEdges(int edges, bool haveweight = false);
    void listCrossing(int roads, int tunnels);
    int getVertexesCountFromEdges();
    int specialPlanet();

protected:
    void initEdges();
    void disposeEdges();

    int _edges;
    SEdge *_edge;
};

class Vertex
{
public:
    Vertex() : _vertexes(0), _matrixFromVertexes(nullptr), _rgbRoads(nullptr)
    {
    }
    Vertex(int vertexes) : _vertexes(vertexes), _matrixFromVertexes(nullptr), _rgbRoads(nullptr)
    {
    }

    ~Vertex()
    {
        disposeMatrix();
        disposeRGBRoads();
    }

    void readMatrix(int vertexes);

    void readRGBRoads(int countOfRGBRoads);
    int countWrongRGBRoads();

    int countRoads();

    int algorithmFloydWarshall();
    int getEdgesCountFromMatrix();

protected:
    void initMatrix();
    void disposeMatrix();

    void initRGBRoads();
    void disposeRGBRoads();
    void colorMatrix();
    int _countOfRGBRoads;
    int *_rgbRoads;

    int _vertexes;
    int **_matrixFromVertexes;
};

class Graph : public Edge, public Vertex
{
public:
    Graph()
    {
    }
    Graph(int edges, int vertexes)
        : Edge(edges), Vertex(vertexes), n(0), monitor1(0), monitor2(0), adjList(nullptr), parent(nullptr)
    {
    }

    ~Graph()
    {
    }

    void printEdges();
    void printMatrix();
    void initMatrixFromEdges();
    void initEdgesFromMatrixOfVertexes();
    void createAdjacencyList(int n, int m);
    void addEdge(int from, int to);
    void setInput();
    void solveGraph();
    void resizeArrays();
    void dfs(int i, int p);

    long long ourMommy(long long children_1, long long children_2);
    int findCommonAncestor(int u, int v);

private:
    void init();
    void dispose();

    int n, monitor1, monitor2;
    Node **adjList;
    int *parent;
};

#endif // GRAPH_H
