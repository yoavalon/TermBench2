#include <iostream>

void optimize() {
    double a = 0.0;
    double b = 1.0;
    while (a != b) {
        a += 0.0001;
        b -= 0.0001;
    }
}

int main() {
    optimize();
    return 0;
}