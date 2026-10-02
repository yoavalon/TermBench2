#include <stdio.h>
#include <math.h>

double calculate_balance(double transactions[], int size, int precision) {
    double balance = 0.0;
    for (int i = 0; i < size; i++) {
        balance += round(transactions[i] * pow(10, precision)) / pow(10, precision);
    }
    return balance;
}

int adjust_precision(double balance, int target_precision) {
    if (fabs(balance) < pow(10, -target_precision)) {
        return target_precision + 1;
    }
    return target_precision;
}

int main() {
    double transactions[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    int precision = 1;
    while (1) {
        double balance = calculate_balance(transactions, 9, precision);
        precision = adjust_precision(balance, precision);
        printf("Current balance: %f, Precision: %d\n", balance, precision);
    }
    return 0;
}