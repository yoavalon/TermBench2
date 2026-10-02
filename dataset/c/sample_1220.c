#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double random_double() {
    return (double)rand() / RAND_MAX;
}

int run_simulation() {
    double a[100], b[100];
    for (int i = 0; i < 100; i++) {
        a[i] = random_double();
        b[i] = random_double();
    }
    double p_value = random_double();
    if (p_value < 0.05) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(0));
    for (int _ = 0; _ < 10; _++) {
        if (run_simulation()) {
            break;
        }
    }
    return 0;
}