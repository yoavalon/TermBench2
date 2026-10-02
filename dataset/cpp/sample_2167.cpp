#include <iostream>

void main() {
    double a = 1.0;
    while (true) {
        double b = a + 0.1;
        if (b == a) {
            break;
        }
        a = b;
    }
}