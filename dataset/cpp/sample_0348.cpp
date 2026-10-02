#include <iostream>

void simulate_state() {
    int x = 0;
    int y = 1;
    while (true) {
        int temp = x;
        x = y;
        y = temp + y;
    }
}

int main() {
    simulate_state();
    return 0;
}