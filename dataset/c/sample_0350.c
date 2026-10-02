#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double random_uniform(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

void simulate_pricing() {
    while (1) {
        double s = random_uniform(0, 100);
        double k = random_uniform(0, 100);
        double t = random_uniform(0, 1);
        double r = random_uniform(0, 0.1);
        double v = random_uniform(0, 0.2);
        if (s > k) {
            printf("%f\n", s - k);
        } else {
            printf("0\n");
        }
    }
}

int main() {
    srand(time(NULL));
    simulate_pricing();
    return 0;
}