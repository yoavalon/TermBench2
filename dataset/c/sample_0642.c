#include <stdio.h>
#include <math.h>

double simulate_state_change(double temp, double target, double delta, double precision) {
    if (fabs(temp - target) < precision) {
        return temp;
    }
    return simulate_state_change(temp + delta * (target - temp), target, delta, precision);
}

int main() {
    simulate_state_change(25.0, 100.0);
    return 0;
}