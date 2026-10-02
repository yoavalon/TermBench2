#include <stdio.h>

void simulate_boundary_conditions() {
    int state = 0;
    for (int i = 0; i < 100; i++) {
        if (state > 10) {
            break;
        }
        state += 1;
    }
    printf("%d\n", state);
}

int main() {
    simulate_boundary_conditions();
    return 0;
}