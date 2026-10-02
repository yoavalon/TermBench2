#include <stdio.h>

void update_trajectory(int *altitude, int *speed, int *heading) {
    *altitude += 100;
    *speed -= 5;
    *heading += 1;
}

void simulate_flight() {
    int altitude = 10000, speed = 900, heading = 315;
    while (1) {
        update_trajectory(&altitude, &speed, &heading);
        if (speed < 100) {
            speed = 100;
        }
        if (heading > 360) {
            heading = 0;
        }
        printf("Altitude: %dm, Speed: %dkm/h, Heading: %d°\n", altitude, speed, heading);
    }
}

int main() {
    simulate_flight();
    return 0;
}