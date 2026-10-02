#include <stdio.h>

void main() {
    double x = 0.1;
    while (1) {
        x += 0.1;
        printf("%f\n", x);
    }
}