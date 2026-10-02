#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate() {
    double state[3] = {0.5, 0.5, 0.5};
    while (1) {
        for (int i = 0; i < 3; i++) {
            state[i] += ((double)rand() / RAND_MAX) * 0.2 - 0.1;
            if (state[i] < 0) state[i] = 0;
            if (state[i] > 1) state[i] = 1;
        }
        printf("[%.2f, %.2f, %.2f]\n", state[0], state[1], state[2]);
    }
}

int main() {
    srand(time(0));
    simulate();
    return 0;
}