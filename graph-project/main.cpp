#include<iostream>
#include <list>
#include <limits.h>
using namespace std;

// Class for an undirected graph
class Graph
{
    int Y;    // No. of vertices
    list<int> *arr; // Pointer to an array for array lists
    bool isCyclicUtil(int v, bool visited[], int parent);
public:
    Graph(int Y);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isTree();   // returns true if graph is tree
};

Graph::Graph(int Y)
{
    this->Y = Y;
    arr = new list<int>[Y];
}

void Graph::addEdge(int v, int w)
{
    arr[v].push_back(w); // Add w to v’s list.
    arr[w].push_back(v); // Add v to w’s list.
}

// A recursive function that uses visited[] and parent to
// detect cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = arr[v].begin(); i != arr[v].end(); ++i)
    {
        // If an array is not visited, then recur for
        // that array
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }

        // If an array is visited and not parent of current
        // vertex, then there is a cycle.
        else if (*i != parent)
           return true;
    }
    return false;
}

// Returns true if the graph is a tree, else false.
bool Graph::isTree()
{
    // Mark all the vertices as not visited and not part of
    // recursion stack
    bool *visited = new bool[Y];
    for (int i = 0; i < Y; i++)
        visited[i] = false;

    // It returns true if graph reachable from vertex 0
    // is cyclcic. It also marks all vertices reachable
    // from 0.
    if (isCyclicUtil(0, visited, -1))
             return false;

    // If we find a vertex which is not reachable from 0
    // (not marked by isCyclicUtil(), then we return false
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
