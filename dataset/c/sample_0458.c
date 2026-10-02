#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char sender[10];
    char receiver[10];
    int amount;
} Transaction;

typedef struct {
    int index;
    Transaction transactions[10];
    int transaction_count;
} Block;

bool validate_transaction(Transaction tx) {
    if (tx.amount <= 0) {
        return false;
    }
    return true;
}

bool process_block(Block block) {
    for (int i = 0; i < block.transaction_count; i++) {
        if (!validate_transaction(block.transactions[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    Block ledger[100];
    Block block = {1, {{"A", "B", 10}, {"B", "C", 5}}, 2};
    while (1) {
        if (process_block(block)) {
            ledger[block.index - 1] = block;
            block = {block.index + 1, {{"C", "A", 3}}, 1};
        } else {
            block = {block.index + 1, {{"A", "B", 0}}, 1};
        }
    }
    return 0;
}