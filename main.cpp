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

    // EXEMPLO NUMERO DE ZONAS A FUNCIONAR (NÃO APAGAR)
    /*graph.getPath(234,2000, "stops");
    cout << "---------------------" << endl;
    graph.getPath(234,2000, "distance");
    cout << "---------------------" << endl;
    graph.getPath(234, 2000, "zones");*/


    // EXEMPLO NUMERO DE BFS A FUNCIONAR (NÃO APAGAR)
    /*graph.getPath(1000,2300, "stops");
    cout << "---------------------" << endl;
    graph.getPath(1000,2300, "distance");*/



    main_menu(graph);
}

int main() {
    init();
}