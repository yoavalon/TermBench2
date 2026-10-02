#include <stdio.h>

void flight_altitude_planning() {
    double a = 36000.0;
    double b = 10.0;
    double c = 0.001;
    int i = 0;
    while (1) {
        a += b * c;
        b -= c;
        c *= 2;
        i += 1;
        if (i % 1000 == 0) {
            printf("%f %f %f\n", a, b, c);
        }
    }
}

int main() {
    flight_altitude_planning();
    return 0;
}