#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate_thermodynamic_state() {
    double state[3];
    double precision = 1e-10;
    srand(time(NULL));

    for (int i = 0; i < 3; i++) {
        state[i] = (double)rand() / RAND_MAX;
    }

    while (1) {
        for (int i = 0; i < 3; i++) {
            state[i] += ((double)rand() / RAND_MAX - 0.5) * 2 * precision;
        }

        double mean = (state[0] + state[1] + state[2]) / 3;
        printf("%f\n", mean);
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}