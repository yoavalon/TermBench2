#include <iostream>

void simulate_state() {
    double x = 0.1, y = 0.2, z = 0.3;
    while (true) {
        x = y;
        y = z;
        z = x + y + z;
        if (x > 1) {
            x = 0.1;
            y = 0.2;
            z = 0.3;
        }
    }
}

int main() {
    simulate_state();
    return 0;
}