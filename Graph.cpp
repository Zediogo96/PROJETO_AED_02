//
// Created by zedio on 21/01/2022.
//
#define INFINITE (INT_MAX / 2)

#include "graph.h"
#include <climits>
#include <set>
#include <fstream>
#include <queue>
#include "Utility.h"



// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, string line, double weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight, line});
    if (!hasDir) nodes[dest].adj.push_back({src, weight, line});
}

void Graph::readStops() {
    ifstream file;
    string filename = "../Data/stops.csv";

    file.open(filename, ifstream::in);

    string code, name, zone, latitude, longitude;

    getline(file, code);

    for (int i = 1; i <= n; i++) {

        getline(file, code, ',');

        getline(file, name, ',') ;

        getline(file, zone, ',') ;

        getline(file, latitude, ',');

        getline(file, longitude);

        nodes[i].code = code;
        nodes[i].name = name;
        nodes[i].zone = zone;
        nodes[i].latitude = stof(latitude);
        nodes[i].longitude = stof(longitude);
        stops.insert({code, i});

    }
    file.close();
}

void Graph::readLines() {
    ifstream file;
    string filename = "../Data/lines.csv";

    file.open(filename, ifstream::in);

    string code, alt_code, name;

    getline(file, code);

    while(!file.eof()) {

        getline(file, code, ',');
        getline(file, alt_code, '-');
        getline(file, name);

        if(code.empty())
            break;

        readLine(code);
    }

    file.close();

    /*for(auto node : nodes) {
        *//*cout << node.name << ": ";*//*
        for (auto edge : node.adj)
            *//*cout << edge.line << " ";*//*
        cout << endl;
    }*/
}

void Graph::readLine(string code) {
    ifstream file;

    for(int i = 0; i < 2; i++) {
        string filename = "../Data/line_" + code + "_" + to_string(i) + ".csv";
        file.open(filename, ifstream::in);

        int num_stops;
        file >> num_stops;

        string source;
        getline(file, source);

        string dest;
        for (int i = 0; i < num_stops; i++) {
            getline(file, dest);

            double lat1 = nodes[stops[source]].latitude;
            double lon1 = nodes[stops[source]].longitude;
            double lat2 = nodes[stops[dest]].latitude;
            double lon2 = nodes[stops[dest]].longitude;

            addEdge(stops[source], stops[dest], code, haversine(lat1,lon1,lat2,lon2));
            source = dest;
        }

        file.close();
    }
}


// Breatdth-First Search: example implementation
// Breatdth-First Search: example implementation
void Graph::bfs(int v) {

    for (int i=1; i<=n; i++) {
        nodes[i].visited = false;
        nodes[i].pred = -1;
    }
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;

    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        /*cout << u << " "; // show node order*/
        for (const auto& e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                nodes[w].pred = u;
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

list<int> Graph::bfsPath(int a, int b) {

    list<int> path;

    int v = b;

    while (v != a) {
        v = nodes[v].pred;
        path.push_front(v);
    }

    for (auto elem : path) {
        cout << nodes[elem].code << " " << nodes[elem].name << endl;
    }
    cout << nodes[b].code << " " << nodes[b].name << endl;

    return path;
}

// ----------------------------------------------------------
// 1) Algoritmo de Dijkstra e caminhos mais curtos
// ----------------------------------------------------------

// ..............................
// a) Distância entre dois nós
// TODO
double Graph::dijkstra_distance(int a, int b) {
    dijkstra(a, b);

    if (nodes[b].dist == INFINITE) return -1;
    return nodes[b].dist;
}

// ..............................
// b) Caminho mais curto entre dois nós
// TODO
list<int> Graph::dijkstra_path(int a, int b) {
    dijkstra(a, b);
    list<int> path;

    if (nodes[b].dist == INFINITE) return path;
    path.push_back(b);
    int v = b;
    while (v != a) {
        v = nodes[v].pred;
        path.push_front(v); // IMPORTANTE FAZER PUSH_FRONT
    }

    for (auto elem : path) cout << nodes[elem].code << " " << nodes[elem].name << endl;

    return path;
}

void Graph::dijkstra(int s, int b) {

    // FIRST -> KEY 2ND -> DISTANCE
    MinHeap<int,int> q(n, -1); // PRIORITY HEAP
    // UTILIZAR VALOR NO PRIMEIRO PARA ORDENAR A ARVORE

    for (int v = 1; v <= n; v++) {
        nodes[v].dist = INFINITE;
        q.insert(v, INFINITE); // SUPOSTAMENTE ERA INFINITE
        nodes[v].visited = false;
    }
    nodes[s].dist = 0; // SOURCE -> where we start the algorithm
    q.decreaseKey(s, 0);
    nodes[s].pred = s;

    while (q.getSize() > 0) {
        int u = q.removeMin();
        nodes[u].visited = true;
        if (u == b) return;

        for (const auto& elem : nodes[u].adj) {

            int e = elem.dest;
            double w = elem.weight;

            if (!nodes[e].visited & (nodes[u].dist + w < nodes[e].dist)) {
                nodes[e].dist = nodes[u].dist + w;
                q.decreaseKey(e, nodes[e].dist);
                nodes[e].pred = u;
            }
        }
    }
}
