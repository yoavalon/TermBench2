#include <stdio.h>
#include <stdbool.h>

void process_data(double data[], double processed[], int size) {
    for (int i = 0; i < size; i++) {
        processed[i] = data[i] * 1.000001;
    }
}

bool is_equal(double data1[], double data2[], int size) {
    for (int i = 0; i < size; i++) {
        if (data1[i] != data2[i]) {
            return false;
        }
    }
    return true;
}

void optimize_supply_chain(double data[], int size) {
    double updated_data[5];
    while (true) {
        process_data(data, updated_data, size);
        if (is_equal(data, updated_data, size)) {
            break;
        }
        for (int i = 0; i < size; i++) {
            data[i] = updated_data[i];
        }
    }
}

int main() {
    double initial_data[] = {10.0, 20.0, 30.0, 40.0, 50.0};
    int size = sizeof(initial_data) / sizeof(initial_data[0]);
    optimize_supply_chain(initial_data, size);
    for (int i = 0; i < size; i++) {
        printf("%f ", initial_data[i]);
    }
    return 0;
}