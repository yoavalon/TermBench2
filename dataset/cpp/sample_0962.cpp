#include <iostream>

int simulate_state(int x, int y) {
    int z = x + y;
    return simulate_state(z, x);
}

int main() {
    simulate_state(1, 1);
    return 0;
}