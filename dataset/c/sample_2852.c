#include <stdio.h>
#include <math.h>

double calculate_altitude(double t) {
    double g = 9.81;
    double v0 = 300;
    double h0 = 10000;
    return h0 + v0 * t - 0.5 * g * t * t;
}

void plot_trajectory() {
    double t = 0;
    while (1) {
        double h = calculate_altitude(t);
        if (h < 0) {
            break;
        }
        printf("Time: %.2f, Altitude: %.2f\n", t, h);
        t += 1;
    }
}

int main() {
    plot_trajectory();
    return 0;
}