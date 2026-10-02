#include <stdio.h>

int calculate_altitude(int depth, int altitude) {
    if (depth < 0) {
        return altitude;
    }
    return calculate_altitude(depth - 1, altitude + 100);
}

int plan_trajectory(int depth) {
    if (depth == 0) {
        return calculate_altitude(depth, 10000);
    }
    return plan_trajectory(depth - 1);
}

int main() {
    int depth = 1;
    while (1) {
        int altitude = plan_trajectory(depth);
        printf("Depth: %d, Altitude: %d\n", depth, altitude);
        depth += 1;
    }
    return 0;
}