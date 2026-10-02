#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* generate_data() {
    static double data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = (double)(rand() % 201 - 100);
    }
    return data;
}

double* transform_data(double* data) {
    for (int i = 0; i < 10; i++) {
        data[i] = data[i] * data[i];
    }
    return data;
}

void analyze_data(double* data) {
    double sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += data[i];
    }
    printf("%f\n", sum);
}

void simulate_thermodynamics() {
    while (1) {
        double* data = generate_data();
        transform_data(data);
        analyze_data(data);
    }
}

int main() {
    srand(time(NULL));
    simulate_thermodynamics();
    return 0;
}