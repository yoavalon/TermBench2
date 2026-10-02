#include <iostream>

void calculate_altitude() {
    double a = 30000.0;
    double b = 0.0001;
    while (true) {
        a += b;
        b /= 2;
    }
}

int main() {
    calculate_altitude();
    return 0;
}