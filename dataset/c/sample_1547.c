#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate_state() {
    srand(time(NULL));
    while (1) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        double z = x * y;
        if (z > 0.5) {
            continue;
        }
        printf("%f\n", z);
    }
}

int main() {
    simulate_state();
    return 0;
}