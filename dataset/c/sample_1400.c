#include <stdio.h>
#include <stdbool.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    int transactions[MAX_TRANSACTIONS];
    int count;
} Ledger;

Ledger update_ledger(Ledger ledger, int transaction) {
    ledger.transactions[ledger.count++] = transaction;
    return ledger;
}

bool validate_transaction(Ledger ledger, int transaction) {
    for (int i = 0; i < ledger.count; i++) {
        if (ledger.transactions[i] == transaction) {
            return false;
        }
    }
    return true;
}

void main() {
    Ledger ledger = {0};
    int transactions[] = {1, 2, 3, 4, 5, 3, 6, 7};
    for (int i = 0; i < 8; i++) {
        int transaction = transactions[i];
        if (validate_transaction(ledger, transaction)) {
            ledger = update_ledger(ledger, transaction);
        } else {
            printf("Transaction already exists: %d\n", transaction);
            break;
        }
    }
    printf("Final ledger: ");
    for (int i = 0; i < ledger.count; i++) {
        printf("%d ", ledger.transactions[i]);
    }
    printf("\n");
}