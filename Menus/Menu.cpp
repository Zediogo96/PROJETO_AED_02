//
// Created by Anibal on 23/01/2022.
//

#include <string>
#include <iomanip>
#include "Menu.h"


using namespace std;

pair<int, int> getInputCodes(Graph graph);
int getDestinationCode(Graph graph);
vector<int> getInputCoordinates(Graph graph);
void select_Stop_Menu(Graph graph, const vector<int>& nearbyStops, int & source);

void main_menu(const Graph& graph){

    char option;
    string startinglocation;
    string destination;

    while (true) {

        std::cout << std::endl;
        std::cout << "_____________________________________" << std::endl;
        std::cout << "|             TRANSPORT             |" << std::endl;
        std::cout << "|             MAIN MENU             |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|   [1] Starting location           |" << std::endl;
        std::cout << "|   [2] Destination                 |" << std::endl;
        std::cout << "|   [3] Route                       |" << std::endl;
        std::cout << "|   [0] Exit                        |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;


        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        switch ((char) option) {
            case '1':
                cin >> startinglocation;
                break;
            case '2':
                cin >> destination;
                break;
            case '3':
                route_options(graph);
                break;
            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}

void route_options(Graph graph){
    int s, d;

    char option;

    vector<int> test;

    pair<int,int> input;

    while (true) {

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|           Route Options           |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|   [1] Shortest distance           |" << std::endl;
        std::cout << "|   [2] Less stops                  |" << std::endl;
        std::cout << "|   [3] Test coordinates            |" << std::endl;
        std::cout << "|   [4] Cheapest route              |" << std::endl;
        std::cout << "|   [0] Go back                     |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        std::cin.ignore();

        switch ((char) option) {
            case '1':

                break;
            case '2':
                input = getInputCodes(graph);
                graph.bfsPath(input.first, input.second);
                break;
            case '3':

                 test = getInputCoordinates(graph);

                select_Stop_Menu(graph,test, s);
                d = getDestinationCode(graph);

                graph.bfsPath(s, d);

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

            std::cout  << "|    [" << k << "] " << setw(3) << left << graph.getNodes()[i].code << " "
                       << setw(30) << left << graph.getNodes()[i].name << "|" << std::endl;
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