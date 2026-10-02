#include <stdio.h>

void flight_trajectory() {
    double a = 1.0, b = 0.0, c = 0.0;
    while (1) {
        c = a + b;
        a = b;
        b = c;
        printf("%f\n", c);
    }
}

int main() {
    flight_trajectory();
    return 0;
}