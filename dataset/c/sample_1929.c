#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double simulate_temperature_change(double initial_temp, double rate, int steps) {
    double temperature = initial_temp;
    for (int i = 0; i < steps; i++) {
        temperature += rate * (double)rand() / RAND_MAX * 2 - 1;
    }
    return temperature;
}

double analyze_simulation_results(double initial_temp, double final_temp) {
    return final_temp - initial_temp;
}

int main() {
    srand(time(NULL));
    double initial_temperature = 300.0;
    double rate_of_change = 0.5;
    int number_of_steps = 1000;
    double final_temperature = simulate_temperature_change(initial_temperature, rate_of_change, number_of_steps);
    double temperature_difference = analyze_simulation_results(initial_temperature, final_temperature);
    printf("Initial Temperature: %f, Final Temperature: %f, Change: %f\n", initial_temperature, final_temperature, temperature_difference);
    return 0;
}