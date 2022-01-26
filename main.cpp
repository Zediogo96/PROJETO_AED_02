#include <iostream>
#include <fstream>
#include "Graph.h"
#include "Menus/Menu.h"

using namespace std;

int countLines(string filename) {
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
    graph.dijkstra_path(1,5);
    cout << graph.dijkstra_distance(1,5) << endl;

    main_menu();
}

int main() {
    init();
    return 0;
}
