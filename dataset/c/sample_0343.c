#include <stdio.h>

void simulate_boundary_conditions() {
    int x = 0;
    while (1) {
        x += 1;
        printf("Thermodynamic state: %d\n", x);
    }
}

int main() {
    simulate_boundary_conditions();
    return 0;
}