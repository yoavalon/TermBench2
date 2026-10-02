#include <stdio.h>
#include <math.h>

double simulate_thermodynamic_state(double temp, double target_temp, double rate, double threshold) {
    if (fabs(temp - target_temp) < threshold) {
        return temp;
    } else {
        temp += rate * (target_temp - temp);
        return simulate_thermodynamic_state(temp, target_temp, rate, threshold);
    }
}

int main() {
    double initial_temp = 300;
    double target_temp = 373;
    double rate = 0.01;
    double threshold = 0.05;
    double result = simulate_thermodynamic_state(initial_temp, target_temp, rate, threshold);
    printf("%f\n", result);
    return 0;
}