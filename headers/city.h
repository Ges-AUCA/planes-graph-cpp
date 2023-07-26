
#ifndef CITY_H
#define CITY_H

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
    //TODO: Implement this function
    return 0;
}
#endif //CITY_H