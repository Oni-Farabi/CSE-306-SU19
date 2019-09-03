#include<iostream>
#include <list>
#include <limits.h>
using namespace std;


class Graph
{
    int Y;
    list<int> *arr;
    bool isCyclicUtil(int v, bool visited[], int parent);
public:
    Graph(int Y);
    void addEdge(int v, int w);
    bool isTree();
};

Graph::Graph(int Y)
{
    this->Y = Y;
    arr = new list<int>[Y];
}

void Graph::addEdge(int v, int w)
{
    arr[v].push_back(w);
    arr[w].push_back(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{

    visited[v] = true;


    list<int>::iterator i;
    for (i = arr[v].begin(); i != arr[v].end(); ++i)
    {

        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }


        else if (*i != parent)
           return true;
    }
    return false;
}


bool Graph::isTree()
{

    bool *visited = new bool[Y];
    for (int i = 0; i < Y; i++)
        visited[i] = false;


    if (isCyclicUtil(0, visited, -1))
             return false;


    for (int u = 0; u < Y; u++)
        if (!visited[u])
           return false;

    return true;
}

int main()
{
    Graph G1(5);
    G1.addEdge(2, 1);
    G1.addEdge(1, 0);
    G1.addEdge(0, 2);
    G1.addEdge(0, 3);
    G1.addEdge(3, 4);
    G1.isTree()? cout << "Graph G1 is Tree\n":
                 cout << "Graph G1 is not Tree\n";

    Graph G2(5);
    G2.addEdge(1, 0);
    G2.addEdge(0, 2);
    G2.addEdge(0, 3);
    G2.addEdge(3, 4);
    G2.isTree()? cout << "Graph G2 is Tree\n":
                 cout << "Graph G2 is not Tree\n";

    return 0;
}
