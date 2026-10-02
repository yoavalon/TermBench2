#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_SIZE 1000000

int* generate_flight_path(int* size) {
    int* data = (int*)malloc(MAX_DATA_SIZE * sizeof(int));
    int altitude = 30000;
    int index = 0;
    while (1) {
        if (altitude > 10000) {
            altitude -= 1000;
        } else {
            altitude += 500;
        }
        data[index] = altitude;
        index++;
        if (index >= MAX_DATA_SIZE) {
            break;
        }
    }
    *size = index;
    return data;
}

void analyze_data(int* data, int size) {
    for (int i = 0; i < size; i++) {
        if (data[i] < 15000) {
            printf("Approaching descent\n");
        } else {
            printf("Cruising at %d feet\n", data[i]);
        }
    }
}

int main() {
    int size;
    int* flight_path = generate_flight_path(&size);
    analyze_data(flight_path, size);
    free(flight_path);
    return 0;
}