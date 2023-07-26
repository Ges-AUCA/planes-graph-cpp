
#ifndef UTIL_H
#define UTIL_H

struct exit_exception : public std::exception {
    const char *what() const noexcept override {
        return "Exiting the program...";
    }
};

struct impossible_route_exception : public std::exception {
    const char *what() const noexcept override {
        return "There is no possible route between the cities with this maximum distance. Try upgrading your planes so they can fly further.";
    }
};
#endif //UTIL_H
