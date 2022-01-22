//
// Created by zedio on 21/01/2022.
//

#ifndef PROJETO2_GRAPH_H
#define PROJETO2_GRAPH_H

#include "MinHeap.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
        string line; //
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        int dist;
        int pred;
        bool visited;
        string code, name, zone;
        float latitude, longitude;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented

    void dijkstra(int s);

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1);

    // ----- Functions to implement in this class -----
    int dijkstra_distance(int a, int b);
    list<int> dijkstra_path(int a, int b);

    int getNumberNodes();

    void readStops();
};

#endif //PROJETO2_GRAPH_H
