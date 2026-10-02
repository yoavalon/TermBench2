#include <stdio.h>

double simulate_state(double temp, double pressure) {
    double result = 0.0;
    for (int i = 0; i < 1000; i++) {
        result += temp * pressure / (i + 1);
    }
    return result;
}

double analyze_simulation(double data[], int len) {
    double total = 0.0;
    for (int i = 0; i < len; i++) {
        total += data[i];
    }
    return total / len;
}

int main() {
    double data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = simulate_state(300, 1);
    }
    double avg = analyze_simulation(data, 10);
    printf("%f\n", avg);
    return 0;
}