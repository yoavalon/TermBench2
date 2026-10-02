#include <stdio.h>
#include <stdlib.h>

void calculate_altitude_profile(int initial_alt, int rate, int steps) {
    int *altitudes = (int *)malloc(steps * sizeof(int));
    int current_alt = initial_alt;
    for (int i = 0; i < steps; i++) {
        altitudes[i] = current_alt;
        current_alt += rate;
    }
    for (int i = 0; i < steps; i++) {
        printf("%d\n", altitudes[i]);
    }
    free(altitudes);
}

int main() {
    calculate_altitude_profile(3000, 500, 10);
    return 0;
}