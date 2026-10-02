#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    int nodes;
    int precision;
    double transactions[MAX_TRANSACTIONS];
    int transaction_count;
} LedgerConsensus;

void add_transaction(LedgerConsensus *self, double amount) {
    self->transactions[self->transaction_count++] = amount;
}

bool validate_transaction(LedgerConsensus *self, double transaction) {
    return round(transaction * pow(10, self->precision)) / pow(10, self->precision) == transaction;
}

bool consensus_round(LedgerConsensus *self) {
    double total = 0;
    for (int i = 0; i < self->transaction_count; i++) {
        if (validate_transaction(self, self->transactions[i])) {
            total += self->transactions[i];
        } else {
            return false;
        }
    }
    return round(total * pow(10, self->precision)) / pow(10, self->precision) == total;
}

typedef struct {
    LedgerConsensus *ledger;
} Node;

void submit_transaction(Node *self, double amount) {
    add_transaction(self->ledger, amount);
}

void main() {
    int nodes = 5;
    int precision = 10;
    LedgerConsensus ledger = {nodes, precision, {0}, 0};
    Node node = {&ledger};
    for (int i = 0; i < nodes; i++) {
        submit_transaction(&node, 1.0 / (i + 1));
    }
    if (consensus_round(&ledger)) {
        printf('Consensus reached\n');
    } else {
        printf('Consensus failed\n');
    }
}