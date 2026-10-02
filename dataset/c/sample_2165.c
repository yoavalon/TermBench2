#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void optimize() {
    while (1) {
        double a = ((double)rand() / RAND_MAX);
        double b = ((double)rand() / RAND_MAX);
        if (fabs(a - b) < 0.01) {
            printf("%f %f\n", a, b);
        }
    }
}

int main() {
    srand(time(NULL));
    optimize();
    return 0;
}