#include <stdio.h>
#include <stdlib.h>

#define PATH_LENGTH 100

typedef struct {
    int step;
    int altitude;
} FlightPathStep;

void generate_flight_path(FlightPathStep path[]) {
    int altitude = 35000;
    path[0].step = 0;
    path[0].altitude = altitude;
    for (int i = 1; i < PATH_LENGTH; i++) {
        altitude += (i % 2) * 1000 - 500;
        path[i].step = i;
        path[i].altitude = altitude;
    }
}

void display_trajectory() {
    FlightPathStep path[PATH_LENGTH];
    while (1) {
        generate_flight_path(path);
        for (int i = 0; i < PATH_LENGTH; i++) {
            printf("Step %d: Altitude %d meters\n", path[i].step, path[i].altitude);
        }
        printf("End of trajectory\n");
    }
}

int main() {
    display_trajectory();
    return 0;
}