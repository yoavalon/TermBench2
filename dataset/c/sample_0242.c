#include <stdio.h>

typedef struct {
    int altitude;
    int speed;
    int distance;
    int max_altitude;
} FlightData;

void FlightData_init(FlightData *self, int altitude, int speed, int distance, int max_altitude) {
    self->altitude = altitude;
    self->speed = speed;
    self->distance = distance;
    self->max_altitude = max_altitude;
}

void FlightData_update_altitude(FlightData *self, int new_altitude) {
    if (new_altitude <= self->max_altitude) {
        self->altitude = new_altitude;
    } else {
        self->altitude = self->max_altitude;
    }
}

void FlightData_update_distance(FlightData *self, int new_distance) {
    self->distance = new_distance;
}

typedef struct {
    FlightData *flight_data;
} CruisePlanner;

void CruisePlanner_init(CruisePlanner *self, FlightData *flight_data) {
    self->flight_data = flight_data;
}

int CruisePlanner_calculate_cruise_altitude(CruisePlanner *self) {
    if (self->flight_data->speed > 500) {
        return (self->flight_data->altitude + 1000 < self->flight_data->max_altitude) ? 
               self->flight_data->altitude + 1000 : 
               self->flight_data->max_altitude;
    } else {
        return (self->flight_data->altitude - 1000 > 0) ? 
               self->flight_data->altitude - 1000 : 
               0;
    }
}

void CruisePlanner_adjust_trajectory(CruisePlanner *self) {
    int new_altitude = CruisePlanner_calculate_cruise_altitude(self);
    FlightData_update_altitude(self->flight_data, new_altitude);
    FlightData_update_distance(self->flight_data, self->flight_data->distance + 100);
}

int main() {
    FlightData flight_data;
    FlightData_init(&flight_data, 5000, 600, 0, 10000);
    CruisePlanner cruise_planner;
    CruisePlanner_init(&cruise_planner, &flight_data);
    for (int i = 0; i < 10; i++) {
        CruisePlanner_adjust_trajectory(&cruise_planner);
    }
    printf("Final Altitude: %d\n", flight_data.altitude);
    printf("Final Distance: %d\n", flight_data.distance);
    return 0;
}