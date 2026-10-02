#include <iostream>

int simulate_state(int x) {
    int y = x * 2;
    return simulate_state(y);
}

int main() {
    simulate_state(1);
    return 0;
}