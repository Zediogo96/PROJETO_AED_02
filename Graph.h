//
// Created by zedio on 21/01/2022.
//
#ifndef PROJETO2_GRAPH_H
#define PROJETO2_GRAPH_H

#include "MinHeap.h"
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

class Graph {
    
    struct Edge {
        int dest;   // Destination node
        double weight; // An integer weight
        string line; // Bus line
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        double dist;
        int pred;
        bool visited;
        string code, name, zone;
        float latitude, longitude;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented
    map<string, int> stops;

    void dijkstra(int s, int b);

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, const string& line, double weight = 1.0F);


    // Algorithms
    bool bfs(int v, int v1);

    void bfsPath(int a, int b);

    // ----- Functions to implement in this class -----
    double dijkstra_distance(int a, int b);

    list<int> dijkstra_path(int a, int b);


    void readStops();
    void readLines();
    void readLine(const string& code);

    int checkIfNameExists(string &s);

    vector<int> findNearNodes(double lat, double lon, int dist);
};

#endif //PROJETO2_GRAPH_H
