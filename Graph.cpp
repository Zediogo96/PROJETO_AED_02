//
// Created by zedio on 21/01/2022.
//
#define INFINITE (ULONG_MAX / 2)

#include "Graph.h"
#include <fstream>
#include <queue>
#include <stack>
#include "Utility.h"


Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {}

void Graph::addEdge(int src, int dest, const string& line, double weight) {
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
}

int Graph::checkIfNameExists(string& s){

    toUpperCase(s);

    for (int i = 1; i <= n; i++) {
        if (nodes[i].name == s) return i;
    }
    return -1;
}

int Graph::checkIfCodeExists(string& s) {
    toUpperCase(s);

    for (int i = 1; i <= n; i++) {
        if (nodes[i].code == s) return i;
    }
    return -1;
}

void Graph::readLine(const string& code) {
    ifstream file;

    for(int i = 0; i < 2; i++) {
        string filename = "../Data/line_" + code + "_" + to_string(i) + ".csv";
        file.open(filename, ifstream::in);

        string num_stops;
        getline(file, num_stops);

        string source;
        getline(file, source);

        string dest;
        for (int j = 0; j < stoi(num_stops); j++) {
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

bool Graph::bfs(int v, int dest) {

    for(int i = 1; i <= n; i++) {
        nodes[i].visited = false;
        nodes[i].pred = -1;
    }

    queue<int> q; 

    q.push(v);
    nodes[v].visited = true;

    while (!q.empty()) { 
        int tmp = q.front(); q.pop();

        for (const auto& e: nodes[tmp].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].pred = tmp;

                if (tmp == dest) return true;
            }
        }
    }
    return false;

}

void Graph::bfsPath(int source, int dest) {

    bfs(source, dest);

    if (!bfs(source, dest)) {
        cout << "Destination is not reachable from this source \n";
        return;
    }

    stack<int> q;

    while (nodes[dest].pred != -1) {
        q.push(dest);
        dest = nodes[dest].pred;
    }

    cout << "[" << nodes[source].code << ": " << nodes[source].name << "]" << endl;

    while(!q.empty()) {
        cout << " -> " << "[" <<  nodes[q.top()].code << ": " << nodes[q.top()].name << "]" << endl;
        q.pop();
    }
}

double Graph::dijkstra_distance(int a, int b) {
    dijkstra(a, b);

    if (nodes[b].dist == INFINITE) return -1;
    return nodes[b].dist;
}

list<int> Graph::dijkstra_path(int a, int b) {
    dijkstra(a, b);
    list<int> path;

    if (nodes[b].dist == INFINITE) return path;
    path.push_back(b);
    int v = b;
    while (v != a) {
        v = nodes[v].pred;
        path.push_front(v);
    }

    for (auto elem : path) cout << "[" << nodes[elem].code << ", " << nodes[elem].name << "]" << endl;

    return path;
}

void Graph::dijkstra(int s, int b) {
    MinHeap<int,double> q(n, -1); 

    for (int v = 1; v <= n; v++) {
        nodes[v].dist = INFINITE;
        q.insert(v, INFINITE);
        nodes[v].visited = false;
        nodes[v].pred = -1;
    }

    nodes[s].dist = 0; 
    q.decreaseKey(s, 0);
    nodes[s].pred = s;

    while (q.getSize() > 0) {
        int u = q.removeMin();
        nodes[u].visited = true;
        if (u == b) return;

        for (const auto& elem : nodes[u].adj) {

            int e = elem.dest;
            double w = elem.weight;

            if (!nodes[e].visited && (nodes[u].dist + w < nodes[e].dist)) {
                nodes[e].dist = nodes[u].dist + w;
                q.decreaseKey(e, nodes[e].dist);
                nodes[e].pred = u;
            }
        }
    }
}

vector<int> Graph::findNearNodes(double lat, double lon, int dist) {

    vector<int> near_nodes;

    for(int i = 1; i <= n; i++)
        if(abs(haversine(nodes[i].latitude, nodes[i].longitude, lat, lon)) <= dist) {
            near_nodes.push_back(i);
        }
    return near_nodes;
}

vector<Graph::Node> Graph::getNodes() {
    return nodes;

}
