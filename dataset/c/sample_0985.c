#include <stdio.h>

double flight_plan(double a, double h, int d) {
    if (d == 0) {
        return h;
    } else {
        return flight_plan(a, h + a * d, d - 1);
    }
}

int main() {
    double a = 0.01;
    double h = 1000;
    int d = 10000;
    printf("%f\n", flight_plan(a, h, d));
    return 0;
}