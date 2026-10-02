#include <stdio.h>

typedef struct {
    int id;
    int altitude;
    char trajectory[10];
} FlightData;

void process_flight_data() {
    FlightData data[] = {
        {1, 30000, "constant"},
        {2, 35000, "ascending"},
        {3, 32000, "descending"},
        {4, 33000, "constant"},
        {5, 31000, "ascending"}
    };
    int length = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < length; i++) {
        if (strcmp(data[i].trajectory, "ascending") == 0) {
            data[i].altitude += 1000;
        } else if (strcmp(data[i].trajectory, "descending") == 0) {
            data[i].altitude -= 500;
        }
    }

    for (int i = 0; i < length; i++) {
        printf("Flight %d: Altitude %d, Trajectory %s\n", data[i].id, data[i].altitude, data[i].trajectory);
    }
}

int main() {
    process_flight_data();
    return 0;
}