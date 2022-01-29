//
// Created by Anibal on 23/01/2022.
//

#ifndef PROJETO2_MENU_H
#define PROJETO2_MENU_H
#include <cstdlib>
#include <iostream>
#include "../Graph.h"

/**
 * @brief The starting menu where the user can select between variations of the "best" path between two bus stops/locations
 * 
 * @param graph Graph of all the bus stops and bus lines
 */
void main_menu(const Graph& graph);

/**
 * @brief Menu where the user inputs two bus stop codes, one for the starting stop and the other for the destination stop
 * 
 * @param graph Graph of all the bus stops and bus lines
 * 
 * @return pair<int, int> A pair containg the integer representation of the source bus stop and destination bus stop, respectively
 */
pair<int, int> getInputCodes(Graph graph);

/**
 * @brief Reads user input for a bus stop code and returns the integer representation of the bus stop in the graph
 * 
 * @param graph Graph of all the bus stops and bus lines
 * 
 * @return int Integer representation of the bus stop
 */
int getDestinationCode(Graph graph);

/**
 * @brief Menu where the user inputs a location in latitude and longitude values as well as a walkable distance. Returns all bus stops within the walkable distance from the location in their integer representation
 * 
 * @param graph Graph of all the bus stops and bus lines
 * 
 * @return vector<int> Array of nodes within the walkable distance from the location given by the user
 */
vector<int> getInputCoordinates(Graph graph);

/**
 * @brief Menu for the best path in regards to fewer bus stops. Has options for the user to choose between giving a bus stop code or a location in latitude and longitude for the starting and ending bus stops.
 * 
 * @param graph Graph of all the bus stops and bus lines
 */
void shortestStopsMenu(Graph graph);

/**
 * @brief Menu displaying all the stops within a walkable distance provided by the user. User then can select one of the stops displayed.
 * 
 * @param graph Graph of all the bus stops and bus lines
 * @param nearbyStops Array of the bus stops within the walkable distance
 * @param source The source/starting bus stop
 */
void select_Stop_Menu(Graph graph, const vector<int>& nearbyStops, int& source);

/**
 * @brief Menu for the best path in regards to shortest distance between bus stops. Has options for the user to choose between giving a bus stop code or a location in latitude and longitude for the starting and ending bus stops.
 * 
 * @param graph Graph of all the bus stops and bus lines
 */
void lessDistanceMenu(Graph graph);
#endif //PROJETO2_MENU_H
