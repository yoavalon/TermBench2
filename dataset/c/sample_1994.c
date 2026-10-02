#include <stdio.h>
#include <stdbool.h>

bool validate_transaction(double amount, double balance) {
    if (amount <= balance) {
        return true;
    }
    return false;
}

double process_transaction(double amount, double balance) {
    if (validate_transaction(amount, balance)) {
        return balance - amount;
    }
    return balance;
}

void update_ledger(double transactions[][2], int num_transactions, double ledger[]) {
    for (int i = 0; i < num_transactions; i++) {
        double amount = transactions[i][0];
        int account = (int)transactions[i][1] - 'A';
        ledger[account] = process_transaction(amount, ledger[account]);
    }
}

int main() {
    double ledger[2] = {1000.0, 500.0};
    double transactions[3][2] = {{150.0, 'A'}, {200.0, 'B'}, {300.0, 'A'}};
    update_ledger(transactions, 3, ledger);
    printf("{A: %.1f, B: %.1f}\n", ledger[0], ledger[1]);
    return 0;
}