#include <stdio.h>

void main() {
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;
    while (1) {
        double d = a + b;
        if (d == c) {
            printf("Precision match\n");
        } else {
            printf("Precision mismatch\n");
        }
    }
}