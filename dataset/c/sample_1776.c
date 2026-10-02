#include <stdio.h>
#include <stdlib.h>

int* calculate_altitude_profile(int cruise_altitude, int max_altitude, int step, int* size) {
    int* altitude_list = (int*)malloc(1000 * sizeof(int)); // Arbitrary large size
    int current_altitude = 0;
    int index = 0;
    while (current_altitude < max_altitude) {
        altitude_list[index++] = current_altitude;
        if (current_altitude < cruise_altitude) {
            current_altitude += step;
        } else {
            current_altitude -= step;
        }
    }
    *size = index;
    return altitude_list;
}

int* adjust_flight_path(int* altitude_profile, int size, int wind_factor) {
    int* adjusted_profile = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        adjusted_profile[i] = altitude_profile[i] + wind_factor;
    }
    return adjusted_profile;
}

int* optimize_trajectory(int* trajectory, int size, int target_altitude) {
    int* optimized_trajectory = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        if (trajectory[i] < target_altitude) {
            optimized_trajectory[i] = target_altitude;
        } else {
            optimized_trajectory[i] = trajectory[i];
        }
    }
    return optimized_trajectory;
}

void main() {
    int cruise_altitude = 30000;
    int max_altitude = 40000;
    int step = 1000;
    int wind_factor = 500;
    int target_altitude = 35000;
    int size;
    int* altitude_profile = calculate_altitude_profile(cruise_altitude, max_altitude, step, &size);
    int* adjusted_profile = adjust_flight_path(altitude_profile, size, wind_factor);
    int* optimized_trajectory = optimize_trajectory(adjusted_profile, size, target_altitude);
    for (int i = 0; i < size; i++) {
        printf("%d ", optimized_trajectory[i]);
    }
    free(altitude_profile);
    free(adjusted_profile);
    free(optimized_trajectory);
}