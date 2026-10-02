#include <stdio.h>

void simulate_state() {
    int x = 0, y = 1;
    while (1) {
        int temp = y;
        y = x + y;
        x = temp;
    }
}

int main() {
    simulate_state();
    return 0;
}