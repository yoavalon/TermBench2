#include <iostream>
#include <cmath>
#include <matplotlibcpp.h>

namespace plt = matplotlibcpp;

double calculate_altitude(double t) {
    double g = 9.81;
    double v0 = 300;
    double h0 = 10000;
    return h0 + v0 * t - 0.5 * g * t * t;
}

void plot_trajectory() {
    double t = 0;
    while (true) {
        double h = calculate_altitude(t);
        if (h < 0) {
            break;
        }
        plt::scatter(t, h, {{"color", "blue"}});
        plt::xlabel("Time (s)");
        plt::ylabel("Altitude (m)");
        plt::title("Flight Trajectory");
        plt::pause(0.01);
        t += 1;
    }
}

int main() {
    plot_trajectory();
    return 0;
}