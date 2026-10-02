#include <stdio.h>

#define ARRAY_SIZE 10

void simulate_temperature_change(int initial_temp, int rate, int steps, int *temperatures) {
    temperatures[0] = initial_temp;
    for (int i = 1; i < steps; i++) {
        temperatures[i] = temperatures[i - 1] + rate;
    }
}

void analyze_data(int *data, int steps, int *max_temp, int *min_temp) {
    *max_temp = data[0];
    *min_temp = data[0];
    for (int i = 1; i < steps; i++) {
        if (data[i] > *max_temp) {
            *max_temp = data[i];
        }
        if (data[i] < *min_temp) {
            *min_temp = data[i];
        }
    }
}

int main() {
    int data[ARRAY_SIZE];
    int max_temp, min_temp;
    simulate_temperature_change(20, 2, ARRAY_SIZE, data);
    analyze_data(data, ARRAY_SIZE, &max_temp, &min_temp);
    printf("%d %d\n", max_temp, min_temp);
    return 0;
}