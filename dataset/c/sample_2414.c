#include <stdio.h>
#include <stdlib.h>

int* calculate_flight_altitude(int max_alt, int rate, int steps) {
    int* altitudes = (int*)malloc(steps * sizeof(int));
    int current_alt = 0;
    for (int i = 0; i < steps; i++) {
        current_alt += rate;
        if (current_alt > max_alt) {
            altitudes[i] = max_alt;
            break;
        }
        altitudes[i] = current_alt;
    }
    return altitudes;
}

int main() {
    int* result = calculate_flight_altitude(30000, 1000, 20);
    for (int i = 0; i < 20; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}