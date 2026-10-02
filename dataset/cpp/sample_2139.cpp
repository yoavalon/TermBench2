#include <iostream>

void simulate(double a, double b, double c) {
    while (true) {
        double d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
}

int main() {
    simulate(1.0, 2.0, 3.0);
    return 0;
}