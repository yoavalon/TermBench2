#include <stdio.h>

typedef struct {
    int altitude;
    int target_altitude;
    int rate_of_climb;
} FlightPath;

typedef struct {
    int altitude;
    int max_speed;
    int wind_speed;
} CruiseAltitude;

void FlightPath_init(FlightPath *flight, int start_altitude, int target_altitude, int rate_of_climb) {
    flight->altitude = start_altitude;
    flight->target_altitude = target_altitude;
    flight->rate_of_climb = rate_of_climb;
}

void FlightPath_climb(FlightPath *flight) {
    flight->altitude += flight->rate_of_climb;
    if (flight->altitude > flight->target_altitude) {
        flight->altitude = flight->target_altitude;
    }
}

void FlightPath_get_status(FlightPath *flight, int *current_alt, int *target_alt) {
    *current_alt = flight->altitude;
    *target_alt = flight->target_altitude;
}

void CruiseAltitude_init(CruiseAltitude *cruise, int altitude, int max_speed, int wind_speed) {
    cruise->altitude = altitude;
    cruise->max_speed = max_speed;
    cruise->wind_speed = wind_speed;
}

void CruiseAltitude_adjust_speed(CruiseAltitude *cruise) {
    cruise->max_speed = cruise->max_speed - cruise->wind_speed * 0.5;
}

int CruiseAltitude_get_speed(CruiseAltitude *cruise) {
    return cruise->max_speed;
}

int main() {
    FlightPath flight;
    CruiseAltitude cruise;
    FlightPath_init(&flight, 1000, 35000, 100);
    CruiseAltitude_init(&cruise, 35000, 800, 20);
    while (1) {
        FlightPath_climb(&flight);
        CruiseAltitude_adjust_speed(&cruise);
        int current_alt, target_alt;
        FlightPath_get_status(&flight, &current_alt, &target_alt);
        int current_speed = CruiseAltitude_get_speed(&cruise);
        if (current_alt == target_alt) {
            printf("Reached target altitude: %d\n", current_alt);
            printf("Cruise speed adjusted to: %d\n", current_speed);
        } else {
            printf("Current altitude: %d, Target altitude: %d\n", current_alt, target_alt);
            printf("Current speed: %d\n", current_speed);
        }
    }
    return 0;
}