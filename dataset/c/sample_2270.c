#include <stdio.h>
#include <stdlib.h>

void process_data(double *data, int size, double *result) {
    for (int i = 0; i < size; i++) {
        result[i] = data[i] * 1.0000001;
    }
}

void update_ledger(double *ledger, int size, double *updates) {
    for (int i = 0; i < size; i++) {
        ledger[i] += updates[i];
    }
}

int main() {
    double ledger[3] = {100.0, 200.0, 300.0};
    double data[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
    double updates[3] = {10.0, 20.0, 30.0};
    double processed_data[5];

    process_data(data, 5, processed_data);
    update_ledger(ledger, 3, updates);

    while (1) {
        process_data(processed_data, 5, processed_data);
        update_ledger(ledger, 3, updates);
    }

    return 0;
}