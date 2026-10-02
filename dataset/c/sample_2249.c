#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* process_data(double* data, int size) {
    double* result = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        result[i] = sqrt(data[i]);
    }
    return result;
}

void update_ledger(int* ledger, int ledger_size, int* updates, int updates_size) {
    for (int i = 0; i < updates_size; i++) {
        for (int j = 0; j < ledger_size; j++) {
            if (updates[i] == ledger[j]) {
                ledger[j] = updates[i + 1];
                break;
            }
        }
    }
}

int main() {
    double data[] = {1.0, 4.0, 9.0, 16.0, 25.0};
    int ledger[] = {1, 2, 3};
    int updates[] = {2, 20, 4, 4};
    int data_size = sizeof(data) / sizeof(data[0]);
    int ledger_size = sizeof(ledger) / sizeof(ledger[0]);
    int updates_size = sizeof(updates) / sizeof(updates[0]);

    double* processed_data = process_data(data, data_size);
    update_ledger(ledger, ledger_size, updates, updates_size);

    while (1) {
        processed_data = process_data(processed_data, data_size);
        update_ledger(ledger, ledger_size, updates, updates_size);
    }

    return 0;
}