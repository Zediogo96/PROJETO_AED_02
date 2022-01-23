//
// Created by zedio on 21/01/2022.
//

#include "graph.h"
#include <climits>
#include <set>
#include <fstream>

#define INFINITE INT_MAX;

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, string line, int weight) {
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

        nodes[i].name = name;
        nodes[i].zone = zone;
        nodes[i].latitude = stof(latitude);
        nodes[i].longitude = stof(longitude);
        stops.insert({code, i});
        //cout << nodes[i].name << " ";
        //cout << nodes[i].zone << " ";
        //cout << nodes[i].latitude << " ";
        //cout << nodes[i].longitude<< endl;

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

        if(code == "")
            break;

        readLine(code);
    }

    file.close();
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
            addEdge(stops[source], stops[dest], code, 1);
            source = dest;
        }

        file.close();
    }
}
// ----------------------------------------------------------
// 1) Algoritmo de Dijkstra e caminhos mais curtos
// ----------------------------------------------------------

// ..............................
// a) Distância entre dois nós
// TODO
int Graph::dijkstra_distance(int a, int b) {
    dijkstra(a);

    if (nodes[b].dist == INT_MAX) return -1;
    return nodes[b].dist;
}

// ..............................
// b) Caminho mais curto entre dois nós
// TODO
list<int> Graph::dijkstra_path(int a, int b) {
    dijkstra(a);
    list<int> path;

    if (nodes[b].dist == INT_MAX) return path;
    path.push_back(b);
    int v = b;
    while (v != a) {
        cout << "!" << v << endl;
        v = nodes[v].pred;
        path.push_front(v); // IMPORTANTE FAZER PUSH_FRONT
    }

    return path;
}


void Graph::dijkstra(int s) {

    // FIRST -> KEY 2ND -> DISTANCE
    MinHeap<int,int> q(n, -1); // PRIORITY HEAP
    set<pair<int,int>> q1; // IDEIA É QUE .BEGIN() DE SET É SEMPRE O MENOR (PQ É ORDENADO)
    // UTILIZAR VALOR NO PRIMEIRO PARA ORDENAR A ARVORE

    for (int v = 1; v <= n; v++) {
        nodes[v].dist = INFINITE;
        q.insert(v, nodes[v].dist); // SUPOSTAMENTE ERA INFINITE
        q1.insert({nodes[v].dist, v});
        nodes[v].visited = false;
    }
    nodes[s].dist = 0; // SOURCE -> where we start the algorithm
    q.decreaseKey(s, 0);
    nodes[s].pred = s;

    while (q.getSize() > 0) {
        int u = q.removeMin();
        cout << "Node " << u << "with distance = " << nodes[u].dist << endl;
        nodes[u].visited = true;

        for (auto elem : nodes[u].adj) {

            int e = elem.dest;
            int w = elem.weight;

            if (!nodes[e].visited & (nodes[u].dist + w < nodes[e].dist)) {
                nodes[e].dist = nodes[u].dist + w;
                q.decreaseKey(e, nodes[e].dist);
                nodes[e].pred = u;
            }
        }
    }
}

// Breadth-First Search:
void Graph::bfs(int v) {
    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}