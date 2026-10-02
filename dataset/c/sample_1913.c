#include <stdio.h>
#include <math.h>

double simulate_temperature(double state, int precision) {
    while (1) {
        state += 0.0001;
        if (round(state * pow(10, precision)) == round(state * pow(10, precision + 1))) {
            break;
        }
    }
    return state;
}

double analyze_state(double initial_state, int target_precision) {
    double result = simulate_temperature(initial_state, target_precision);
    return result;
}

void main() {
    double initial_value = 0.0;
    int precision_level = 4;
    double final_state = analyze_state(initial_value, precision_level);
    printf("%f\n", final_state);
}