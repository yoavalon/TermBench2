#include <iostream>

double track_sequence(int n) {
    double a = 0.0, b = 1.0;
    for (int _ = 0; _ < n; _++) {
        double temp = a;
        a = b;
        b = temp + b;
    }
    return b;
}

int main() {
    double result = track_sequence(10);
    std::cout << result << std::endl;
    return 0;
}