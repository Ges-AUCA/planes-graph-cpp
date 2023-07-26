#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <functional>
#include <optional>

#define EXIT_FAILURE 1;


struct City {
public:
    City(std::string name, double latitude, double longitude)
            : name(std::move(name)), latitude(latitude), longitude(longitude) {}

    std::string getName() const { return name; }

    double getLatitude() const { return latitude; }

    double getLongitude() const { return longitude; }

private:
    std::string name;
    double latitude;
    double longitude;
};

double calculateDistance(const City &origin, const City &destination) {
    return 0;
}

struct Route {

public:
    Route(const City& origin, const City& destination, const std::optional<double> param)
            : origin(origin), destination(destination) {
            distance = param.has_value() ? param.value() : calculateDistance(origin, destination);
    }

    City getOrigin() const { return origin; }

    City getDestination() const { return destination; }

    double getDistance() const { return distance; }
private:
    City origin;
    City destination;
    double distance;
};

struct exit_exception : public std::exception {
    const char *what() const noexcept override {
        return "Exiting the program...";
    }
};


std::vector<Route> findShortestRoute(const std::vector<City> &) {
    std::cout << "Creating a route between two cities." << std::endl;
    auto fullRoute = std::vector<Route>();
    return fullRoute;
}

std::vector<Route> findBestRouteMap(const std::vector<City> &) {
    std::cout << "Creating a route map between all the cities." << std::endl;
    auto fullMap = std::vector<Route>();
    return fullMap;
}


std::vector<City> parseCitiesFromCSV(const std::string &filename) {

    //The file is expected to be in the following format:
    //City Name, Latitude, Longitude, ...
    std::vector<City> cities;

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return cities;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        std::string latitude;
        std::string longitude;

        if (
                std::getline(iss, name, ',') && // Read until the first comma (the name)
                std::getline(iss, latitude, ',') && // Read until the second comma (the latitude)
                std::getline(iss, longitude, ',') // Read until the third comma (the longitude)
                )
            cities.emplace_back(name, std::stod(latitude), std::stod(longitude));
        else
            std::cerr << "Error parsing line: " << line << std::endl;
    }

    return cities;
}

std::function<std::vector<Route>(const std::vector<City> &)> getRouteOption() {
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
        routeOption(cities);
    } catch (const exit_exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
