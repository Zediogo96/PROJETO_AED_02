#include <iostream>
#include <fstream>
#include "Graph.h"
#include "Menus/Menu.h"

using namespace std;

int countLines(const string& filename) {

    int lines_nr = 0;
    std::string line;
    std::ifstream file(filename);

    getline(file, line);

    while (std::getline(file, line))
        lines_nr++;

    return lines_nr;
}

void init(){

    Graph graph = Graph(countLines("../Data/stops.csv"), true);
    graph.readStops();
    graph.readLines();



    graph.dijkstra(2410,1439);
   graph.dijkstra_path(2410,1439);

    /*graph.bfsPath(100,340);*/
    cout << "----------------------------" << endl;



    graph.dijkstraZones(2410);
    graph.dijkstra_path(2410, 1439);

    /* graph.findNearNodes(41.1488,-8.610426, 100);*/

    /*main_menu(graph);*/

}

int main() {
    init();
    return 0;
}
