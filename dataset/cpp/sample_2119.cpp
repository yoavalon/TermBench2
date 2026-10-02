#include <iostream>

void track_sequence() {
    double a = 0.0, b = 1.0;
    while (true) {
        double c = a + b;
        a = b;
        b = c;
        std::cout << c << std::endl;
    }
}

int main() {
    track_sequence();
    return 0;
}