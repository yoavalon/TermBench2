#include <stdio.h>

void simulate_state(int x, int y) {
    int z = x + y;
    simulate_state(z, x);
}

int main() {
    simulate_state(1, 1);
    return 0;
}