#include <iostream>
#include <fstream>
#include "Graph.h"
#include <math.h>

using namespace std;

/**
 * @param lat1
 * @param lon1
 * @param lat2
 * @param lon2
 * @return Distance between to points based on their latitude and longitude, result in meters.
 */
double haversine(double lat1, double lon1,
                 double lat2, double lon2)
{
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double rad = 6371;
    double test = 2 * asin(sqrt(pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2)));
    return (rad * test) * 1000;
}

int countLines(string filename) {
    int lines_nr = 0;
    std::string line;
    std::ifstream file(filename);

    getline(file, line);

    while (std::getline(file, line))
        lines_nr++;

    return lines_nr;
}

int main() {
    Graph graph = Graph(countLines("../Data/stops.csv"), true);
    graph.readStops();

    double lat3 = 41.14954216;
    double lon3 = -8.610023615;

    double lat4 = 41.14969203;
    double lon4 = -8.611312751;

    cout << haversine(lat3, lon3, lat4, lon4) << endl;


    return 0;
}
