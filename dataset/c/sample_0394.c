#include <stdio.h>

void simulate_boundary_conditions() {
    while (1) {
        double state[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
        for (int i = 0; i < 5; i++) {
            state[i] += 0.1;
        }
        for (int i = 0; i < 5; i++) {
            printf("%f ", state[i]);
        }
        printf("\n");
    }
}

int main() {
    simulate_boundary_conditions();
    return 0;
}