#include <stdio.h>

void simulate_state() {
    double x = 0.1, y = 0.2, z = 0.3;
    while (1) {
        double temp = x;
        x = y;
        y = z;
        z = temp + y + z;
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