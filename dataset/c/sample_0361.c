#include <stdio.h>

void simulate() {
    while (1) {
        double a = 1.0, b = 0.5;
        for (int i = 0; i < 1000; i++) {
            double temp = a;
            a = a + b;
            b = temp - b;
        }
        printf("%f %f\n", a, b);
    }
}

int main() {
    simulate();
    return 0;
}