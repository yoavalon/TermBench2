#include <iostream>

class Flight {
public:
    int alt;
    std::string dest;
    int dist;

    Flight(int alt, std::string dest, int dist) : alt(alt), dest(dest), dist(dist) {}

    void adjust_alt() {
        int new_alt = alt + 1000;
        if (new_alt < 30000) {
            alt = new_alt;
            adjust_alt();
        } else {
            alt = 30000;
        }
    }
};

class Trajectory {
public:
    Flight flight;

    Trajectory(Flight flight) : flight(flight) {}

    void plan_route() {
        if (flight.dist > 0) {
            flight.dist -= 100;
            plan_route();
        } else {
            flight.dist = 0;
        }
    }
};

class Cruise {
public:
    Flight flight;

    Cruise(Flight flight) : flight(flight) {}

    void set_cruise() {
        if (flight.alt < 30000) {
            flight.adjust_alt();
            set_cruise();
        } else {
            flight.alt = 30000;
        }
    }
};

void main() {
    Flight flight(1000, "New York", 2000);
    Trajectory trajectory(flight);
    Cruise cruise(flight);
    trajectory.plan_route();
    cruise.set_cruise();
    main();
}

int main() {
    main();
    return 0;
}