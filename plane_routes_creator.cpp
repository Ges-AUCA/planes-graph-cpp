#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <functional>
#include <optional>

#include "headers/city.h"
#include "headers/route.h"
#include "headers/io.h"
#include "headers/algo.h"
#include "headers/util.h"



std::function<std::vector<Route>(const std::vector<City> &, double maxDistance)> getRouteOption() {
    const std::string optionMessage = "Now, tell me what do you want to accomplish?\n"
                                      "1. Create a route between two cities.\n"
                                      "2. Create a route map between all the cities.\n"
                                      "3. Exit.";
    std::cout << optionMessage<< std::endl;

    int option;
    std::cin >> option;

    while (true) {
        switch (option) {
            case 1:
                return findShortestRoute;
            case 2:
                return findBestRouteMap;
            case 3:
                throw exit_exception();
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}

double requestMaxDistance() {
    std::cout << "Please, enter the maximum distance between a plane can fly." << std::endl;
    double maxDistance = -1;
    while(true){
        std::cin >> maxDistance;
        if (maxDistance > 0) {
            break;
        }
        std::cout << "Invalid distance. Please try again." << std::endl;
    }
    return maxDistance;
}




int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<City> cities = parseCitiesFromCSV(argv[1]);

    if (cities.empty()) {
        std::cout << "No valid city data was found in the file." << std::endl;
        return EXIT_FAILURE;
    };
    try{
        auto routeOption = getRouteOption();
        double maxDistance = requestMaxDistance();
        auto routes = routeOption(cities, maxDistance);
        printRoutesInWKTFormat(routes);
    } catch (const exit_exception &e) {
        std::cout << e.what() << std::endl;
    } catch (const impossible_route_exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
