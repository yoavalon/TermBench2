#include <stdio.h>

// Function to simulate temperature change
void* simulate_temp_change(double initial_temp, double rate, double time_step) {
    static double current_temp;
    current_temp = initial_temp;
    while (1) {
        current_temp += rate * time_step;
        // Yield behavior in C using a static variable and a pointer
        return &current_temp;
    }
}

// Function to analyze sequence
void analyze_sequence(void* (*sequence_func)()) {
    double* value;
    while (1) {
        value = (double*)sequence_func();
        printf("Current Temperature: %.2fK\n", *value);
    }
}

// Main function
void main() {
    double initial_temp = 300;
    double rate = 0.01;
    double time_step = 1;
    analyze_sequence(simulate_temp_change);
}