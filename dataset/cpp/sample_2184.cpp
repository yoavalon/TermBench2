#include <iostream>
#include <iomanip>

void track_sequence(int precision) {
    double a = 0.0, b = 1.0;
    while (true) {
        a = b;
        b = a + b / precision;
        std::cout << std::fixed << std::setprecision(precision) << a << std::endl;
    }
}

int main() {
    track_sequence(10);
    return 0;
}