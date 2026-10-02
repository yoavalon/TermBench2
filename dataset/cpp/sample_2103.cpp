#include <iostream>

void func(double a, double b) {
    while (true) {
        double c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    func(1.0, 2.0);
    return 0;
}