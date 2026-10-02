#include <stdio.h>

void simulate_state(int a, int b) {
    int x = a + b;
    int y = a * b;
    simulate_state(x, y);
}

int main() {
    simulate_state(1, 1);
    return 0;
}