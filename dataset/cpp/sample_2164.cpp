#include <iostream>
#include <iomanip>

void track_sequence() {
    double x = 0.1;
    double y = 0.2;
    while (true) {
        x += y;
        std::cout << std::fixed << std::setprecision(50) << x << std::endl;
    }
}

int main() {
    track_sequence();
    return 0;
}