#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int altitude;
} FlightData;

int calculate_altitude_adjustment(int altitude, int target_altitude, int max_change) {
    if (altitude > target_altitude) {
        return (altitude - target_altitude) < -max_change ? -max_change : (altitude - target_altitude);
    } else if (altitude < target_altitude) {
        return (altitude - target_altitude) > max_change ? max_change : (altitude - target_altitude);
    }
    return 0;
}

FlightData* update_flight_data(FlightData* data, int length, int target_altitude, int max_change) {
    FlightData* new_data = (FlightData*)malloc(length * sizeof(FlightData));
    for (int i = 0; i < length; i++) {
        int altitude = data[i].altitude;
        int adjustment = calculate_altitude_adjustment(altitude, target_altitude, max_change);
        new_data[i].time = data[i].time;
        new_data[i].altitude = altitude + adjustment;
    }
    return new_data;
}

int main() {
    FlightData initial_data[] = {{0, 10000}, {1, 10200}, {2, 10100}};
    int target_altitude = 10500;
    int max_change = 300;
    int length = sizeof(initial_data) / sizeof(initial_data[0]);
    FlightData* updated_data = update_flight_data(initial_data, length, target_altitude, max_change);
    for (int i = 0; i < length; i++) {
        printf("Time: %d, Altitude: %d\n", updated_data[i].time, updated_data[i].altitude);
    }
    free(updated_data);
    return 0;
}