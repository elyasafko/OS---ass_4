#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <stack>
#include <list>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Graph
{
    int vertices;   // No. of vertices
    list<int> *adj; // A dynamic array of adjacency lists
public:
    // Constructor and destructor
    Graph(int edges, int vertices, int random_seed)
    {
        srand(random_seed);
        this->vertices = vertices;
        adj = new list<int>[vertices];
        for (size_t i = 0; i < (size_t)edges; i++)
        {
            int v = rand() % vertices;
            int w = rand() % vertices;
            addEdge(v, w);
        }
    }
    ~Graph() { delete[] adj; } // To avoid memory leak

    // function to add an edge to graph
    void addEdge(int v, int w);

    // Method to check if this graph is Eulerian or not
    int isEulerian();

    // Method to check if all non-zero degree vertices are connected
    bool isConnected();

    // Function to do DFS starting from v. Used in isConnected();
    void DFSUtil(int v, bool visited[]);
};

#endif // GRAPH_HPP
