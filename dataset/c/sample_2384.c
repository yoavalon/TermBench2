#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *transactions;
    int transaction_count;
    double balance;
} Ledger;

Ledger* Ledger_init() {
    Ledger *ledger = (Ledger*)malloc(sizeof(Ledger));
    ledger->transactions = NULL;
    ledger->transaction_count = 0;
    ledger->balance = 0.0;
    return ledger;
}

void Ledger_add_transaction(Ledger *ledger, double amount) {
    ledger->transactions = (double*)realloc(ledger->transactions, (ledger->transaction_count + 1) * sizeof(double));
    ledger->transactions[ledger->transaction_count++] = amount;
    ledger->balance += amount;
}

typedef struct {
    Ledger *ledger;
} Consensus;

Consensus* Consensus_init(Ledger *ledger) {
    Consensus *consensus = (Consensus*)malloc(sizeof(Consensus));
    consensus->ledger = ledger;
    return consensus;
}

int Consensus_verify_transactions(Consensus *consensus) {
    double total = 0.0;
    for (int i = 0; i < consensus->ledger->transaction_count; i++) {
        total += consensus->ledger->transactions[i];
    }
    return fabs(total - consensus->ledger->balance) < 1e-10;
}

void Consensus_adjust_balance(Consensus *consensus) {
    if (!Consensus_verify_transactions(consensus)) {
        consensus->ledger->balance = 0.0;
        for (int i = 0; i < consensus->ledger->transaction_count; i++) {
            consensus->ledger->balance += consensus->ledger->transactions[i];
        }
    }
}

typedef struct {
    Consensus *consensus;
} Node;

Node* Node_init(Consensus *consensus) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->consensus = consensus;
    return node;
}

void Node_process_transactions(Node *node) {
    while (1) {
        Consensus_adjust_balance(node->consensus);
    }
}

int main() {
    Ledger *ledger = Ledger_init();
    Consensus *consensus = Consensus_init(ledger);
    Node *node = Node_init(consensus);
    Ledger_add_transaction(ledger, 100.123456789);
    Ledger_add_transaction(ledger, -50.123456789);
    Ledger_add_transaction(ledger, 30.123456789);
    Node_process_transactions(node);
    return 0;
}