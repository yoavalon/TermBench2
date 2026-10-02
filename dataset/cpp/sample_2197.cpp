#include <iostream>

void func(double a, double b) {
    double c = a / b;
    while (true) {
        double d = c * 1000000;
        int e = static_cast<int>(d);
        double f = d - e;
        c = f;
    }
}

int main() {
    func(1, 3);
    return 0;
}