

#ifndef ALGO_H
#define ALGO_H


#include "city.h"
#include "route.h"
#include <vector>
#include <iostream>

std::vector<Route> findShortestRoute(const std::vector<City> &, double maxDistance) {
    std::cout << "Creating a route between two cities." << std::endl;
    auto fullRoute = std::vector<Route>();
    //TODO: Implement this function
    return fullRoute;
}

std::vector<Route> findBestRouteMap(const std::vector<City> &, double maxDistance) {
    std::cout << "Creating a route map between all the cities." << std::endl;
    auto fullMap = std::vector<Route>();
    //TODO: Implement this function
    return fullMap;
}

#endif //ALGO_H