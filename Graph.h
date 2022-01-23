//
// Created by zedio on 21/01/2022.
//

#ifndef PROJETO2_GRAPH_H
#define PROJETO2_GRAPH_H

#include "MinHeap.h"
#include <vector>
#include <list>
#include <map>
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

    void dijkstra(int s);

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, string line, double weight = 1.0F);

    // ----- Functions to implement in this class -----
    int dijkstra_distance(int a, int b);

    list<int> dijkstra_path(int a, int b);


    void readStops();
    void readLines();
    void readLine(string code);


    /** TO TEST THE WEIGHTS **/
    void printWeights() {
        for (int i = 1; i <= n; i++) {
            for (const auto& elem : nodes[i].adj) {
                cout << elem.weight << " ";
            }
        }
    }


};

#endif //PROJETO2_GRAPH_H
