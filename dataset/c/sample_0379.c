#include <stdio.h>

void simulate_boundary_conditions() {
    int state = 0;
    while (1) {
        state = (state + 1) % 100;
        printf("State: %d\n", state);
    }
}

int main() {
    simulate_boundary_conditions();
    return 0;
}