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

/**
 * @brief The graph class utilized for this project. We used a single graph, an instance of this class.
 *
 */
class Graph {

    /**
    * @brief The structure of our graph's edges. They represent the bus lines that connects the bus stops.
    *
    */
    struct Edge {
        int dest;            /*!< Stores the integer representation of the destination node  */
        double weight;       /*!< Stores the distance between the destination node and the source node */
        string line;         /*!< Stores the line which the edge belongs to and connects the nodes it's linking */
    };

    /**
     * @brief The structure of our graph's nodes. They represent the bus stops.
     *
     */
    struct Node {
        list<Edge> adj;              /*!< Stores all the edges (bus lines) connected to the node (stop) */
        double dist;                 /*!< Stores the distance needed to arrive to the node (used in Dijkstra's algorithm) */
        int pred;                    /*!< Stores the integer representation of its predecessor node (node from which we arrived to this one) */
        bool visited;                /*!< A flag to check whether this node has already been visited by an algorithm when it traverses the graph */
        string code, name, zone;     /*!< Stores specific information about the bus stop that the node represents */
        float latitude, longitude;   /*!< Stores the values for the bus stop's latitude and longitude */
    };

    int n;                   /*!< The number of nodes in the graph */
    bool hasDir;             /*!< Flag for whether the graph is directed or undirected */
    vector<Node> nodes;      /*!< Container for all the nodes of the graph */
    map<string, int> stops;  /*!< Maps each bus stop code to its node integer representation. Used to access a node in the graph by its bus stop code. */

public:
    /**
     * @brief Graph's constructor method
     *
     * @param nodes Number of nodes to be created in the graph
     * @param dir   Boolean flag for whether the graph is directed or undirected. By default it's undirected (=false)
     */
    Graph(int nodes, bool dir = false);

    /**
    * @brief Adds an edge to the graph
    *
    * @param src The source node the edge will point to
    * @param dest The destination node the edge will point to
    * @param line The bus line the edge is associated with
    * @param weight The distance between the source and destination nodes
    */
    void addEdge(int src, int dest, const string& line, double weight = 1.0F);

    /**
     * @brief Breath-First Search (BFS) algorithm. Used to determine the shortest path between two nodes in an unweighted graph. Time complexity of O(V + E), V being the number of nodes and E the number of edges of the graph.
     *
     * @param v The source node
     * @param dest The destination node
     *
     * @return boolean Whether a path was found between the nodes
     */
    bool bfs(int v, int v1);

    /**
    * @brief Displays the path calculated with the BFS algorithm between two nodes
    *
    * @param a The source node
    * @param b The destination node
    */
    void bfsPath(int a, int b);

    /**
     * @brief Returns the distance calculated with Dijkstra's algorithm between the two provided nodes
     *
     * @param a The source node
     * @param b The destination node
     *
     * @return double Distance between the nodes in meters
     */
    double dijkstra_distance(int a, int b);

    /**
     * @brief Returns the path calculated with Dijkstra's algorithm between the two provided nodes
     *
     * @param a The source node
     * @param b The destination node
     *
     * @return list<int> A list of the nodes belonging to the path in order from source to destination
     */
    list<int> getPath(int a, int b, const string& type);

    /**
     * @brief Method used to read data from the 'stops.csv' file and fill the nodes of the graph with the read data
     *
     */
    void readStops();

    /**
     * @brief Method used to read data from the 'lines.csv' file and then call the method to read the specific files of every line
     *
     */
    void readLines();

    /**
     * @brief Method used to read data from each specified line file, in both directions of the line, and creating the edges of the graph with the read data
     *
     * @param code
     */
    void readLine(const string& code);

    /**
     * @brief Method to find nodes within a specified distance from a location given in latitude and longitude values
     *
     * @param lat The location's latitude
     * @param lon The location's longitude
     * @param dist The maximum distance from the location that a node can be
     *
     * @return vector<int> A vector of nodes within the distance provided from the given location
     */
    vector<int> findNearNodes(double lat, double lon, int dist);

    /**
    * @brief Method to check if there is a bus stop with the code passed as the argument
    *
    * @param s An input bus stop code made by the user
    *
    * @return int The integer representation in the graph of the bus stop with the same code
    */
    int checkIfCodeExists(string &s);

    /**
     * @brief Method that returns the vector containing all the nodes of the graph
     *
     * @return vector<Node> Vector storing all the nodes that belong to the graph
     */
    vector<Node> getNodes() { return nodes; }

    /**
     * @brief Dijkstra's algorithm. used to find the shortest path between two nodes based on the number of zone changes (the less the better). Time complexity of O(V + E*log(V)) as a priority queue is used, where V is the number of nodes and E the number of edges in the graph.
     *
     * @param src The source node
     */
    void dijkstraZones(int src, int b);

    /**
     * @brief Dijkstra's algorithm. Used to find the shortest distance in a weighted graph between two nodes. Time complexity of O(V + E*log(V)) as a priority queue is used, where V is the number of nodes and E the number of edges in the graph.
     *
     * @param s The source node
     * @param b The destination node
     */
    void dijkstra(int s, int b);
};

#endif //PROJETO2_GRAPH_H
