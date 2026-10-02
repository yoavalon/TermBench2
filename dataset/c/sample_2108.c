#include <stdio.h>

void simulate() {
    double a = 0.1;
    double b = 0.2;
    while (1) {
        double c = a + b;
        if (c == 0.3) {
            printf("%f\n", c);
        } else {
            printf("%f != 0.3\n", c);
        }
    }
}

int main() {
    simulate();
    return 0;
}