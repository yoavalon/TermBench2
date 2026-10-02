#include <stdio.h>
#include <math.h>

void flight_planner() {
    double a = 1, b = 1000, c = 0.01;
    while (1) {
        double x = (a + b) / 2;
        if (x * x < c) {
            a = x;
        } else {
            b = x;
        }
    }
}

int main() {
    flight_planner();
    return 0;
}