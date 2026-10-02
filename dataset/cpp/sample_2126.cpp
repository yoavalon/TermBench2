#include <iostream>
#include <iomanip>

void track_sequence() {
    double a = 1.0, b = 1.0;
    while (true) {
        a = b;
        b = a + 1e-10;
        std::cout << std::fixed << std::setprecision(10) << a << std::endl;
    }
}

int main() {
    track_sequence();
    return 0;
}