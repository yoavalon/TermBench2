#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate_thermo_state() {
    double a[10], b[10];
    double dot_product = 0.0;

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        a[i] = (double)rand() / RAND_MAX;
    }

    while (1) {
        dot_product = 0.0;
        for (int i = 0; i < 10; i++) {
            b[i] = (double)rand() / RAND_MAX;
            dot_product += a[i] * b[i];
        }
        for (int i = 0; i < 10; i++) {
            a[i] = dot_product;
        }
    }
}

int main() {
    simulate_thermo_state();
    return 0;
}