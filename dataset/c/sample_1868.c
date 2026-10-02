#include <stdio.h>
#include <math.h>

#define MAX_SIZE 3

void optimize_supply_chain(double data[], double precision, double result[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        double value = data[i];
        double adjusted_value = round(value / precision) * precision;
        result[i] = adjusted_value;
    }
}

int main() {
    double data[] = {123.456, 789.123, 456.789};
    double precision = 0.01;
    double optimized_data[MAX_SIZE];

    optimize_supply_chain(data, precision, optimized_data);

    printf("[");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%f", optimized_data[i]);
        if (i < MAX_SIZE - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}