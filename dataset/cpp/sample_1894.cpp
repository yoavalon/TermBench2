#include <iostream>

double calculate_altitude() {
    double x = 1.0;
    for (int _ = 0; _ < 1000; ++_) {
        x = x / 2 + 0.5;
    }
    return x;
}

int main() {
    calculate_altitude();
    return 0;
}