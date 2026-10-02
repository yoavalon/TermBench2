#include <stdio.h>

void simulate_thermo_state() {
    int x = 0;
    while (1) {
        x += 1;
        int y = x * x;
        int z = y + 2 * x + 1;
        printf("%d\n", z);
    }
}

int main() {
    simulate_thermo_state();
    return 0;
}