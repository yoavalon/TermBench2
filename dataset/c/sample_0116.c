#include <stdio.h>
#include <stdbool.h>

double calculate_energy(double state[], double boundary[], int size) {
    double energy = 0;
    for (int i = 0; i < size; i++) {
        energy += state[i] * boundary[i];
    }
    return energy;
}

bool check_condition(double energy, double threshold) {
    if (energy > threshold) {
        return true;
    }
    return false;
}

int main() {
    double state[] = {300, 101325, 0.0224};
    double boundary[] = {0.001, -0.0001, 0.001};
    double threshold = 500;
    double energy = calculate_energy(state, boundary, 3);
    bool condition_met = check_condition(energy, threshold);
    if (condition_met) {
        printf("Condition met: %f\n", energy);
    } else {
        printf("Condition not met: %f\n", energy);
    }
    return 0;
}