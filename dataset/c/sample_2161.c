#include <stdio.h>

void simulate_state() {
    double a = 1.0, b = 1.0, c = 1.0;
    while (1) {
        a = (a + b) / 2;
        b = (b + c) / 2;
        c = (a + c) / 2;
    }
}

int main() {
    simulate_state();
    return 0;
}