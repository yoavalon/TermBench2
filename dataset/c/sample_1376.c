#include <stdio.h>
#include <string.h>

double calculate_altitude(int cruise_speed, int distance, int wind_speed, const char* wind_direction) {
    int speed = strcmp(wind_direction, "against") == 0 ? cruise_speed - wind_speed : cruise_speed + wind_speed;
    double time = (double)distance / speed;
    double altitude = (double)cruise_speed * time / 10;
    return altitude;
}

double adjust_altitude(double altitude, int adjustments[], int size) {
    for (int i = 0; i < size; i++) {
        if (adjustments[i] > 0) {
            altitude += adjustments[i];
        } else {
            altitude -= abs(adjustments[i]);
        }
    }
    return altitude;
}

int main() {
    int cruise_speed = 800;
    int distance = 2000;
    int wind_speed = 50;
    const char* wind_direction = "against";
    int adjustments[] = {100, -50, 30};
    int size = sizeof(adjustments) / sizeof(adjustments[0]);
    double initial_altitude = calculate_altitude(cruise_speed, distance, wind_speed, wind_direction);
    double final_altitude = adjust_altitude(initial_altitude, adjustments, size);
    printf("%f\n", final_altitude);
    return 0;
}