#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double simulate_decay() {
    static double a = 1.0, b = 1.0;
    double result = a;
    b = a * ((double)rand() / RAND_MAX * 0.5 + 0.5);
    a = b;
    return result;
}

int main() {
    srand(time(NULL));
    while (1) {
        printf("%f\n", simulate_decay());
    }
    return 0;
}