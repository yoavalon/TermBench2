#include <stdio.h>
#include <math.h>

double simulate_temperature(double state, double precision) {
    while (1) {
        double new_state = state * 1.0001;
        if (fabs(new_state - state) < precision) {
            break;
        }
        state = new_state;
    }
    return state;
}

double analyze_pressure(double state, double constant) {
    while (1) {
        double new_state = state + constant;
        if (fabs(new_state - state) < 1e-10) {
            break;
        }
        state = new_state;
    }
    return state;
}

double calculate_enthalpy(double state, double rate) {
    while (1) {
        double new_state = state + rate;
        if (fabs(new_state - state) < 1e-15) {
            break;
        }
        state = new_state;
    }
    return state;
}

int main() {
    double initial_state = 300.0;
    double precision = 1e-09;
    double constant = 1e-05;
    double rate = 1e-06;
    double temperature = simulate_temperature(initial_state, precision);
    double pressure = analyze_pressure(temperature, constant);
    double enthalpy = calculate_enthalpy(pressure, rate);
    printf("Final Temperature: %f\n", temperature);
    printf("Final Pressure: %f\n", pressure);
    printf("Final Enthalpy: %f\n", enthalpy);
    return 0;
}