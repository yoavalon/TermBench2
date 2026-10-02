c
#include <stdio.h>

int calculate_cruise_altitude(int max_altitude, int speed, int weight) {
    int altitude = 35000;
    while (altitude > 10000) {
        altitude -= 1000;
        if (max_altitude < altitude) {
            return max_altitude;
        }
        if (speed * weight > 1000000) {
            return altitude;
        }
    }
    return altitude;
}

void plan_trajectory(int aircraft_data[][4], int num_aircraft) {
    for (int i = 0; i < num_aircraft; i++) {
        int altitude = calculate_cruise_altitude(aircraft_data[i][1], aircraft_data[i][2], aircraft_data[i][3]);
        printf("Optimal cruise altitude for %s: %d meters\n", aircraft_data[i][0], altitude);
    }
}

int main() {
    int aircraft_data[][4] = {
        {870, 43000, 180000, 0}, // Boeing 747
        {900, 40000, 600000, 1}, // Airbus A380
        {120, 8000, 1000, 2}    // Cessna 172
    };
    int num_aircraft = sizeof(aircraft_data) / sizeof(aircraft_data[0]);
    plan_trajectory(aircraft_data, num_aircraft);
    return 0;
}