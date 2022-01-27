//
// Created by Anibal on 23/01/2022.
//

#include <string>
#include "Menu.h"


using namespace std;

void main_menu(Graph graph){
    char option;
    string startinglocation;
    string destination;

    while (true) {
        std::cout << std::endl;
        std::cout << "_____________________________________" << std::endl;
        std::cout << "|            TRANSPORT              |" << std::endl;
        std::cout << "|           MAIN   MENU             |" << std::endl;
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
    char option;
    string source, dest;
    int s, d;

    while (true) {

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|           Route Options           |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|   [1] Shortest distance           |" << std::endl;
        std::cout << "|   [2] Less stops                  |" << std::endl;
        std::cout << "|   [3] Fewest line changes         |" << std::endl;
        std::cout << "|   [4] Cheapest route              |" << std::endl;
        std::cout << "|   [0] Go back                     |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        switch ((char) option) {
            case '1':

                break;
            case '2':

                do {
                    cout << "From which stop do you want calculate a route? ";
                    cin >> source;
                    s = graph.checkIfNameExists(source);
                }
                while (graph.checkIfNameExists(source) == -1);

                do {
                    cout << "Where do you want to go? ";
                    cin >> dest;
                    d = graph.checkIfNameExists(dest);
                }
                while (graph.checkIfNameExists(dest) == -1);
                graph.bfsPath(s,d);
                break;
            case '3':

                break;
            case '4':

                break;
            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}