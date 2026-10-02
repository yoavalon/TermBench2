#include <stdio.h>

void main() {
    double a = 1.0;
    while (1) {
        double b = a + 0.1;
        if (b == a) {
            break;
        }
        a = b;
    }
}