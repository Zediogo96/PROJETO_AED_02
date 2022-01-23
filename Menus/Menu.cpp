//
// Created by Anibal on 23/01/2022.
//

#include "Menu.h"

void main_menu(){
    char option;

    while (true) {
        std::cout << std::endl;
        std::cout << "_____________________________________" << std::endl;
        std::cout << "|            TRANSPORT              |" << std::endl;
        std::cout << "|           MAIN   MENU             |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|   [1] Route Options               |" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|   [0] Exit                        |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        switch ((char) option) {
            case '1':
                route_options();
                break;
            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}

void route_options(){
    char option;

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
                destination();
                break;
            case '2':
                destination();
                break;
            case '3':
                destination();
                break;
            case '4':
                destination();
                break;
            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}

void destination(){
    char option;

    while (true) {

        std::cout << "_____________________________________" << std::endl;
        std::cout << "|    WHERE WOULD YOU LIKE TO GO ?   |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|                                   |" << std::endl;
        std::cout << "|   [1] Starting location           |" << std::endl;
        std::cout << "|   [2] Destination                 |" << std::endl;
        std::cout << "|   [0] Exit                        |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;

        std::cout << "Please input your choice: " << std::endl << std::flush;
        std::cin >> option;

        switch ((char) option) {
            case '1':
                route_options();
                break;
            case '0': return;
            default: std::cout << "Invalid Input \n:";
                system("pause");
        }
    }
}