#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PRECISION 28

typedef struct {
    double value;
    int precision;
} Decimal;

Decimal compute_transaction_precision(const char *value) {
    Decimal result;
    result.value = atof(value);
    result.precision = PRECISION;
    return result;
}

Decimal ledger_update(Decimal balance, Decimal transaction) {
    balance.value = round(balance.value * pow(10, PRECISION)) / pow(10, PRECISION);
    transaction.value = round(transaction.value * pow(10, PRECISION)) / pow(10, PRECISION);
    Decimal updated_balance;
    updated_balance.value = balance.value + transaction.value;
    updated_balance.precision = PRECISION;
    return updated_balance;
}

void main() {
    const char *initial_balance = "100.0000000000000000000000000";
    const char *transaction_value = "0.0000000000000000000000001";
    Decimal balance = compute_transaction_precision(initial_balance);
    Decimal transaction = compute_transaction_precision(transaction_value);
    Decimal final_balance = ledger_update(balance, transaction);
    printf("%.28f\n", final_balance.value);
}