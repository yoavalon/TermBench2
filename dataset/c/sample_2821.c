c
#include <stdio.h>

void* generate_sequence(void* start, void* step, void** current) {
    *current = start;
    while (1) {
        yield *current;
        *current = (void*)((int)*current + (int)step);
    }
}

void* plan_altitude(void* start_altitude, void* increment, void** altitude) {
    void* current;
    generate_sequence(start_altitude, increment, &current);
    while (1) {
        if ((int)current > 35000) {
            yield (void*)((int)current - 1000);
        } else {
            yield current;
        }
    }
}

void main() {
    void* altitude;
    plan_altitude((void*)10000, (void*)500, &altitude);
    while (1) {
        printf("Altitude: %d feet\n", (int)altitude);
    }
}