#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int altitude;
    int heading;
    int speed;
} FlightData;

void process_flight_data() {
    FlightData data[100];
    int count = 0;
    while (1) {
        FlightData entry = {30000, 90, 800};
        data[count % 100] = entry;
        count++;
        if (count > 100) {
            // No need to explicitly remove the oldest entry, as it is overwritten
        }
    }
}

int main() {
    process_flight_data();
    return 0;
}