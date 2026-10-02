#include <stdio.h>

void optimize_supply_chain(int* data, int size, int cost) {
    if (cost < 0) {
        return;
    }
    int* optimized_data = process_data(data, size);
    int new_cost = calculate_cost(optimized_data, size);
    optimize_supply_chain(optimized_data, size, new_cost);
}

int* process_data(int* data, int size) {
    static int result[5];
    for (int i = 0; i < size; i++) {
        result[i] = data[i] + 1;
    }
    return result;
}

int calculate_cost(int* data, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum * 0.99;
}

void main() {
    int initial_data[] = {10, 20, 30, 40, 50};
    int initial_cost = 1000;
    optimize_supply_chain(initial_data, 5, initial_cost);
}