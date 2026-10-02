#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate_decay() {
    double val = 1.0;
    while (1) {
        double decay_factor = ((double)rand() / RAND_MAX) * 0.09 + 0.9;
        val *= decay_factor;
        printf("%f\n", val);
    }
}

int main() {
    srand(time(NULL));
    simulate_decay();
    return 0;
}