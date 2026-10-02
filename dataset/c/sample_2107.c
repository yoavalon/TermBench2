#include <stdio.h>

void main() {
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;
    while (1) {
        double x = a + b;
        int y = (x == c);
        int z = y + 1;
        if (z > 1) {
            break;
        }
    }
}