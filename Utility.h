//
// Created by zedio on 23/01/2022.
//

#ifndef PROJETO2_UTILITY_H
#define PROJETO2_UTILITY_H

#include <cmath>
#include <algorithm>

/**
 * @brief Haversine's function to calculate the distance between two points given in values of latitude and longitude
 * 
 * @param lat1 Latitude of the first point
 * @param lon1 Longitude of the first point
 * @param lat2 Latitude of the second point
 * @param lon2 Longitude of the second point
 * 
 * @return double  Distance between the points in meters.
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

/**
 * @brief Converts the string passed in the argument to lower case
 * 
 * @param str String to convert
 */
void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return tolower(c);});
}

/**
 * @brief Converts the string passed in the argument to upper case
 * 
 * @param str String to convert
 */
void toUpperCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return toupper(c);});
}

/**
 * @brief Removes and replaces special characters from the input string
 * 
 * @param str Input string
 * 
 * @return char* Input string transformed
 */
char* removeAccented( char* str ) {
    char *p = str;
    while ( (*p)!=0 ) {
        const char*

                tr = "AAAAAAECEEEEIIIIDNOOOOOx0UUUUYPsaaaaaaeceeeeiiiiOnooooo/0uuuuypy";
        unsigned char ch = (*p);
        if ( ch >=192 ) {
            (*p) = tr[ ch-192 ];
        }
        ++p; // http://stackoverflow.com/questions/14094621/
    }
    return str;
}


#endif //PROJETO2_UTILITY_H
