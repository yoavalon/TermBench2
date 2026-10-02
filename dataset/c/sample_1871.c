#include <stdio.h>

void main() {
    double a = 1.0, b = 1.0, c = 0.0;
    for (int i = 0; i < 10; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    printf("%f\n", c);
}