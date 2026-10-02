#include <stdio.h>

int* initialize_ledger() {
    static int ledger[10] = {0};
    return ledger;
}

int* update_ledger(int* ledger, int index, int value) {
    if (0 <= index && index < 10) {
        ledger[index] += value;
    }
    return ledger;
}

int* consensus_mechanic(int* ledger, int transactions[][2], int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        ledger = update_ledger(ledger, transactions[i][0], transactions[i][1]);
    }
    return ledger;
}

int main() {
    int* ledger = initialize_ledger();
    int transactions[][2] = {{0, 5}, {1, 3}, {2, 8}};
    int num_transactions = sizeof(transactions) / sizeof(transactions[0]);
    int* final_ledger = consensus_mechanic(ledger, transactions, num_transactions);
    for (int i = 0; i < 10; i++) {
        printf("%d ", final_ledger[i]);
    }
    printf("\n");
    return 0;
}