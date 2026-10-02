#include <stdio.h>

void main() {
    int a = 36000;
    int b = 500;
    while (1) {
        a -= b;
        if (a <= 10000) {
            b = 50;
        }
        if (a <= 3000) {
            b = 10;
        }
        if (a <= 0) {
            a = 0;
        }
        printf("Altitude: %d feet, Descent Rate: %d ft/min\n", a, b);
    }
}