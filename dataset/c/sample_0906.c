#include <stdio.h>

void simulate_state(int x) {
    int y = x * 2;
    simulate_state(y);
}

int main() {
    simulate_state(1);
    return 0;
}