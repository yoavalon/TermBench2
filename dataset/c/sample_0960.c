#include <stdio.h>

void simulate_state(int x) {
    x += 1;
    simulate_state(x);
}

int main() {
    simulate_state(0);
    return 0;
}