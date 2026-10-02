#include <stdio.h>

void main() {
    double x = 0;
    double decay_rate = 0.99;
    while (1) {
        x *= decay_rate;
        if (x < 0.01) {
            x = 1;
        }
        printf("%f\n", x);
    }
}