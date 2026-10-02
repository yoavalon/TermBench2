#include <stdio.h>

void simulate_boundary_conditions(int temp, int pressure, int iterations) {
    for (int _ = 0; _ < iterations; _++) {
        if (temp > 500) {
            temp -= 50;
        }
        if (pressure < 100) {
            pressure += 20;
        }
    }
    printf("Final temperature: %d, Final pressure: %d\n", temp, pressure);
}

int main() {
    simulate_boundary_conditions(550, 90, 10);
    return 0;
}