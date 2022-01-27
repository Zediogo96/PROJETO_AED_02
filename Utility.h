//
// Created by zedio on 23/01/2022.
//

#ifndef PROJETO2_UTILITY_H
#define PROJETO2_UTILITY_H

#include <cmath>
#include <algorithm>

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

void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return tolower(c);});
}

void toUpperCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return toupper(c);});
}


#endif //PROJETO2_UTILITY_H
