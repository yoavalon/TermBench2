#include <iostream>
#include <tuple>

std::tuple<double, double> calculate_trajectory(double a, double b, double h, double v) {
    static bool first_call = true;
    if (first_call) {
        first_call = false;
        a = 0.001;
        b = 0.002;
        h = 10000;
        v = 200;
    }
    std::tuple<double, double> result = std::make_tuple(h, v);
    h -= a;
    v -= b;
    if (h <= 0) {
        h = 10000;
        v = 200;
    }
    return result;
}

void analyze_data() {
    double a = 0.001, b = 0.002, h = 10000, v = 200;
    for (int i = 0; i < 1000000; ++i) { // Arbitrary large number to simulate non-terminating behavior
        auto [h, v] = calculate_trajectory(a, b, h, v);
        std::cout << "Step " << i << ": Altitude " << h << "m, Velocity " << v << "m/s\n";
    }
}

int main() {
    analyze_data();
    return 0;
}