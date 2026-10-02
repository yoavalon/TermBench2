#include <iostream>

void simulate_state() {
    int x = 1, y = 1;
    while (true) {
        x = x + y;
        y = x - y;
        if (x == 0) {
            x = 1;
            y = 1;
        }
    }
}

int main() {
    simulate_state();
    return 0;
}