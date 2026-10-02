#include <stdio.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char transactions[MAX_TRANSACTIONS][10];
    int count;
} Ledger;

int validate_transaction(const char *transaction, Ledger *ledger) {
    for (int i = 0; i < ledger->count; i++) {
        if (strcmp(transaction, ledger->transactions[i]) == 0) {
            return 0;
        }
    }
    strcpy(ledger->transactions[ledger->count], transaction);
    ledger->count++;
    return 1;
}

void process_block(const char *block[], int block_size, Ledger *ledger) {
    for (int i = 0; i < block_size; i++) {
        if (!validate_transaction(block[i], ledger)) {
            fprintf(stderr, "Invalid transaction detected\n");
            exit(1);
        }
    }
}

void main() {
    Ledger ledger = {{}, 0};
    const char *block[] = {"tx1", "tx2", "tx3"};
    process_block(block, 3, &ledger);
    printf("Block processed successfully\n");
}