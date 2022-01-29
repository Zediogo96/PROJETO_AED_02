//
// Created by Anibal on 23/01/2022.
//

#include <string>
#include <iomanip>
#include "Menu.h"


using namespace std;

void main_menu(const Graph& graph){

    char option;
    string startinglocation;
    string destination;

    while (true) {

        std::cout << std::endl;
        std::cout << "_____________________________________" << std::endl;
        std::cout << "|                STCP               |" << std::endl;
        std::cout << "|             MAIN MENU             |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|   Select your desired route:      |" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|   [1] Fewer Number of Stops       |" << std::endl;
        std::cout << "|   [2] Less Distance               |" << std::endl;
        std::cout << "|   [3] Less Zone Changes           |" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|   [0] Exit                        |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;


        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        switch ((char) option) {
            case '1':
                shortestStopsMenu(graph);
                break;
            case '2':
                lessDistanceMenu(graph);
                break;
            case '3':
                lessZonesMenu(graph);
                break;
            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}

void shortestStopsMenu(Graph graph){
    int s, d;

    char option;

    vector<int> test;

    pair<int,int> input;

    while (true) {

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|         FEWER STOPS ROUTE         |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|   [1] By Location                 |" << std::endl;
        std::cout << "|   [2] By Code of Stops            |" << std::endl;
        std::cout << "|   [0] Go back                     |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        std::cin.ignore();

        switch ((char) option) {
            case '1':

                test = getInputCoordinates(graph);
                select_Stop_Menu(graph,test, s);
                d = getDestinationCode(graph);
                graph.bfsPath(s, d);

                break;
            case '2':
                input = getInputCodes(graph);
                graph.bfsPath(input.first, input.second);
                break;
            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}

void lessDistanceMenu(Graph graph) {
    int s, d;

    char option;

    vector<int> test;

    pair<int,int> input;

    while (true) {

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|       SHORTEST DISTANCE ROUTE     |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|   [1] By Location                 |" << std::endl;
        std::cout << "|   [2] By Code of Stops            |" << std::endl;
        std::cout << "|   [0] Go back                     |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        std::cin.ignore();

        switch ((char) option) {
            case '1':

                test = getInputCoordinates(graph);
                select_Stop_Menu(graph,test, s);
                d = getDestinationCode(graph);
                graph.dijkstra_path(s,d);
                cout << "\n Your total distance for this route is: " <<
                     graph.dijkstra_distance(s, d) / 1000.0f << " kilometers! \n";

                break;
            case '2':

                input = getInputCodes(graph);
                graph.dijkstra(input.first, input.second);
                graph.dijkstra_path(input.first, input.second);

                cout << "\n Your total distance for this route is: " <<
                graph.dijkstra_distance(input.first, input.second) / 1000.0f << " kilometers! \n";

                break;
            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}

void lessZonesMenu(Graph graph) {
    int s, d;

    char option;

    vector<int> test;

    pair<int,int> input;

    while (true) {

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|       SHORTEST DISTANCE ROUTE     |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|   [1] By Location                 |" << std::endl;
        std::cout << "|   [2] By Code of Stops            |" << std::endl;
        std::cout << "|   [0] Go back                     |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        std::cin.ignore();

        switch ((char) option) {
            case '1':

                test = getInputCoordinates(graph);
                select_Stop_Menu(graph,test, s);
                d = getDestinationCode(graph);

                graph.dijkstraZones(s);
                graph.dijkstra_path(s,d);


                break;

            case '2':

                input = getInputCodes(graph);
                graph.dijkstraZones(input.first);
                graph.dijkstra_path(input.first, input.second);

                cout << "\n Your total distance for this route is: " <<
                graph.dijkstra_distance(input.first, input.second) / 1000.0f << " kilometers! \n";

                break;

            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}

pair<int, int> getInputCodes(Graph graph) {

    string source, dest;
    int s, d;

    do {
        cout << "From which stop (code) do you want calculate a route? " << endl;
        std::getline(std::cin, source);
        s = graph.checkIfCodeExists(source);
    }
    while (graph.checkIfCodeExists(source) == -1);

    do {
        cout << "Where do you want to go? (code) " << endl;
        std::getline(std::cin, dest);
        d = graph.checkIfCodeExists(dest);
    }
    while (graph.checkIfCodeExists(dest) == -1);

    return make_pair(s, d);
}

vector<int> getInputCoordinates(Graph graph) {

    double lat, lon;
    int distFoot;


    cout << "Where are you located right now? (Coordinates, for example [41.1495, -8.6100] )" << endl;
    cout << "Latitude:" ; cin >> lat;
    cin.ignore();
    cout << "Longitude:" ; cin >> lon;
    cin.ignore();

    cout << "How much are you willing to walk to a nearby stop? (in Meters)" << endl;
    cin >> distFoot;

    return graph.findNearNodes(lat, lon, distFoot);
}

int getDestinationCode(Graph graph) {

    cin.ignore();
    string dest;
    int d;

    do {
        cout << "To which stop do you wish to travel? (code)" << endl;
        std::getline(cin, dest);
        d = graph.checkIfCodeExists(dest);
    } while (graph.checkIfCodeExists(dest) == -1);

    return d;
}

void select_Stop_Menu(Graph graph, const vector<int>& nearbyStops, int & source) {

    int option;

    while(true) {
        cout << "_____________________________________________" << std::endl;
        cout << "|               STOP SELECTION              |" << std::endl;
        cout << "|___________________________________________|" << std::endl;
        cout << "|     Choose one of the nearest stops       |" << endl;
        cout << "|             to your Location:             |" << endl;
        cout << "|                                           |" << endl;

        cout<<setfill(' ');

        int k = 1;
        for (auto i : nearbyStops) {
            string s = graph.getNodes()[i].code + "   " + graph.getNodes()[i].name;

            std::cout << "|    [" << k << "] " << s << setw(37 - s.length() - to_string(k).length())<< "|" << std::endl;
            k++;
        }
        std::cout << "|                                           |" << std::endl;
        std::cout << "|    [0] EXIT                               |" << std::endl;
        std::cout << "|___________________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;
        if(option > 0 && option < nearbyStops.size() + 1) {
            source = graph.checkIfCodeExists(graph.getNodes()[nearbyStops[option - 1]].code);

            return;
        }
        else if (option == 0) return;
        else {
            std::cout << "Invalid Input \n:";
            system("pause");
            cin.ignore();
        }
    }
}