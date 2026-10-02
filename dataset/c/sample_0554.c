#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int altitude;
    int cruise_altitude;
    int rate_of_climb;
    int rate_of_descent;
} FlightParameters;

typedef struct {
    int min_altitude;
    int max_altitude;
} BoundaryConditions;

void FlightParameters_init(FlightParameters *flight, int initial_altitude, int cruise_altitude, int rate_of_climb, int rate_of_descent) {
    flight->altitude = initial_altitude;
    flight->cruise_altitude = cruise_altitude;
    flight->rate_of_climb = rate_of_climb;
    flight->rate_of_descent = rate_of_descent;
}

void FlightParameters_update_altitude(FlightParameters *flight, const char *action) {
    if (strcmp(action, "climb") == 0) {
        flight->altitude += flight->rate_of_climb;
    } else if (strcmp(action, "descend") == 0) {
        flight->altitude -= flight->rate_of_descent;
    }
}

bool FlightParameters_is_at_cruise(const FlightParameters *flight) {
    return flight->altitude >= flight->cruise_altitude;
}

void BoundaryConditions_init(BoundaryConditions *boundaries, int min_altitude, int max_altitude) {
    boundaries->min_altitude = min_altitude;
    boundaries->max_altitude = max_altitude;
}

bool BoundaryConditions_is_within_bounds(const BoundaryConditions *boundaries, int altitude) {
    return boundaries->min_altitude <= altitude && altitude <= boundaries->max_altitude;
}

int BoundaryConditions_adjust_boundary(const BoundaryConditions *boundaries, int altitude) {
    if (altitude < boundaries->min_altitude) {
        return boundaries->min_altitude;
    } else if (altitude > boundaries->max_altitude) {
        return boundaries->max_altitude;
    }
    return altitude;
}

void flight_control_system(FlightParameters *flight, BoundaryConditions *boundaries) {
    while (true) {
        if (!BoundaryConditions_is_within_bounds(boundaries, flight->altitude)) {
            flight->altitude = BoundaryConditions_adjust_boundary(boundaries, flight->altitude);
        }
        if (!FlightParameters_is_at_cruise(flight)) {
            const char *action = flight->altitude < flight->cruise_altitude ? "climb" : "descend";
            FlightParameters_update_altitude(flight, action);
        }
    }
}

int main() {
    FlightParameters flight;
    BoundaryConditions boundaries;
    FlightParameters_init(&flight, 5000, 35000, 1000, 500);
    BoundaryConditions_init(&boundaries, 5000, 40000);
    flight_control_system(&flight, &boundaries);
    return 0;
}