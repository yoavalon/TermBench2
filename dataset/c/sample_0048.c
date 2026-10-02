#include <stdio.h>

int simulate_thermal_state(int initial_temp, int boundary_temp, int cooling_rate) {
    int temp = initial_temp;
    int steps = 0;
    while (temp > boundary_temp) {
        temp -= cooling_rate;
        steps += 1;
    }
    return steps;
}

int main() {
    int result = simulate_thermal_state(1000, 300, 50);
    printf("%d\n", result);
    return 0;
}