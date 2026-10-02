#include <stdio.h>

void simulate_state() {
    int x = 1, y = 1;
    while (1) {
        int temp = x;
        x = x + y;
        y = temp - y;
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