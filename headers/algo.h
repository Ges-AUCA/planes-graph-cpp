

#ifndef ALGO_H
#define ALGO_H


#include "city.h"
#include "flight.h"
#include <vector>
#include <iostream>

std::vector<Flight> findShortestRoute(const std::vector<City> &, double maxDistance, const City &origin,
                                      const City &destination) {
    std::cout << "Creating a route between two cities." << std::endl;
    auto fullRoute = std::vector<Flight>();
    //TODO: Implement this function
    return fullRoute;
}

std::vector<Flight> findBestRouteMap(const std::vector<City> &, double maxDistance) {
    std::cout << "Creating a route map between all the cities." << std::endl;
    auto fullMap = std::vector<Flight>();
    //TODO: Implement this function
    return fullMap;
}

#endif //ALGO_H