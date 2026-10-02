#include <stdio.h>
#include <stdlib.h>

int update_altitude(int current_alt, int target_alt, int rate) {
    if (current_alt < target_alt) {
        return current_alt + rate < target_alt ? current_alt + rate : target_alt;
    } else if (current_alt > target_alt) {
        return current_alt - rate > target_alt ? current_alt - rate : target_alt;
    }
    return current_alt;
}

void simulate_flight() {
    int current_altitude = 0;
    int target_altitude = 35000;
    int rate_of_change = 1000;
    int max_iterations = 1000;
    for (int i = 0; i < max_iterations; i++) {
        current_altitude = update_altitude(current_altitude, target_altitude, rate_of_change);
        if (current_altitude == target_altitude) {
            break;
        }
    }
    printf("Flight reached target altitude: %d\n", current_altitude);
}

int main() {
    simulate_flight();
    return 0;
}