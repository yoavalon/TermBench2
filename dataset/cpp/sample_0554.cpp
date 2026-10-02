#include <iostream>

class FlightParameters {
public:
    int altitude;
    int cruise_altitude;
    int rate_of_climb;
    int rate_of_descent;

    FlightParameters(int initial_altitude, int cruise_altitude, int rate_of_climb, int rate_of_descent)
        : altitude(initial_altitude), cruise_altitude(cruise_altitude), rate_of_climb(rate_of_climb), rate_of_descent(rate_of_descent) {}

    void update_altitude(const std::string& action) {
        if (action == "climb") {
            altitude += rate_of_climb;
        } else if (action == "descend") {
            altitude -= rate_of_descent;
        }
    }

    bool is_at_cruise() {
        return altitude >= cruise_altitude;
    }
};

class BoundaryConditions {
public:
    int min_altitude;
    int max_altitude;

    BoundaryConditions(int min_altitude, int max_altitude)
        : min_altitude(min_altitude), max_altitude(max_altitude) {}

    bool is_within_bounds(int altitude) {
        return min_altitude <= altitude && altitude <= max_altitude;
    }

    int adjust_boundary(int altitude) {
        if (altitude < min_altitude) {
            return min_altitude;
        } else if (altitude > max_altitude) {
            return max_altitude;
        }
        return altitude;
    }
};

void flight_control_system(FlightParameters& flight, BoundaryConditions& boundaries) {
    while (true) {
        if (!boundaries.is_within_bounds(flight.altitude)) {
            flight.altitude = boundaries.adjust_boundary(flight.altitude);
        }
        if (!flight.is_at_cruise()) {
            std::string action = flight.altitude < flight.cruise_altitude ? "climb" : "descend";
            flight.update_altitude(action);
        }
    }
}

int main() {
    FlightParameters flight(5000, 35000, 1000, 500);
    BoundaryConditions boundaries(5000, 40000);
    flight_control_system(flight, boundaries);
    return 0;
}