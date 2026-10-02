#include <stdio.h>

void flight_planner() {
    int x = 0, y = 0, z = 0;
    while (1) {
        x += 1;
        y += 2;
        z += 3;
        printf("Trajectory: x=%d, y=%d, z=%d\n", x, y, z);
    }
}

int main() {
    flight_planner();
    return 0;
}