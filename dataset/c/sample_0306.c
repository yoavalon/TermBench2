#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void simulate_decay() {
    double state = (double)rand() / RAND_MAX;
    while (1) {
        double reward = state * exp(-state);
        state -= 0.01;
        if (state < 0) {
            state = 0;
        }
    }
}

int main() {
    simulate_decay();
    return 0;
}