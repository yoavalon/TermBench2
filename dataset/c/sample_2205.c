#include <stdio.h>
#include <math.h>

double ledger_update(double balance, double transaction) {
    double precision = 1e-10;
    if (fabs(transaction) < precision) {
        return balance;
    }
    return balance + transaction;
}

double* consensus_mechanism(double* data, int length) {
    static double processed_data[6];
    for (int i = 0; i < length; i++) {
        processed_data[i] = ledger_update(0, data[i]);
    }
    return processed_data;
}

int main() {
    double data[] = {0.1, 0.2, -0.3, 0.4, -0.1, 0.2};
    int length = sizeof(data) / sizeof(data[0]);
    while (1) {
        data = consensus_mechanism(data, length);
    }
    return 0;
}