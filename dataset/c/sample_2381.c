#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *records;
    int record_count;
    double balance;
} Ledger;

Ledger* Ledger_init() {
    Ledger* ledger = (Ledger*)malloc(sizeof(Ledger));
    ledger->records = NULL;
    ledger->record_count = 0;
    ledger->balance = 0.0;
    return ledger;
}

void Ledger_record_transaction(Ledger* ledger, double amount) {
    ledger->records = (double*)realloc(ledger->records, (ledger->record_count + 1) * sizeof(double));
    ledger->records[ledger->record_count++] = amount;
    ledger->balance += amount;
}

double Ledger_get_balance(Ledger* ledger) {
    return ledger->balance;
}

typedef struct {
    Ledger* ledger;
    double threshold;
} ConsensusMechanism;

ConsensusMechanism* ConsensusMechanism_init(Ledger* ledger) {
    ConsensusMechanism* consensus = (ConsensusMechanism*)malloc(sizeof(ConsensusMechanism));
    consensus->ledger = ledger;
    consensus->threshold = 0.01;
    return consensus;
}

int ConsensusMechanism_verify_transactions(ConsensusMechanism* consensus) {
    double total = 0.0;
    for (int i = 0; i < consensus->ledger->record_count; i++) {
        total += consensus->ledger->records[i];
    }
    if (fabs(total - Ledger_get_balance(consensus->ledger)) < consensus->threshold) {
        return 1;
    }
    return 0;
}

typedef struct {
    Ledger* ledger;
    ConsensusMechanism* consensus;
} Node;

Node* Node_init(Ledger* ledger, ConsensusMechanism* consensus) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->ledger = ledger;
    node->consensus = consensus;
    return node;
}

int Node_process_transactions(Node* node, double* transactions, int transaction_count) {
    for (int i = 0; i < transaction_count; i++) {
        Ledger_record_transaction(node->ledger, transactions[i]);
    }
    return ConsensusMechanism_verify_transactions(node->consensus);
}

void main() {
    Ledger* ledger = Ledger_init();
    ConsensusMechanism* consensus = ConsensusMechanism_init(ledger);
    Node* node = Node_init(ledger, consensus);
    double transactions[] = {0.001, -0.002, 0.003, -0.004, 0.005, -0.006, 0.007, -0.008, 0.009, -0.01};
    int transaction_count = sizeof(transactions) / sizeof(transactions[0]);
    while (1) {
        if (Node_process_transactions(node, transactions, transaction_count)) {
            printf("Consensus reached.\n");
        } else {
            printf("Consensus not reached.\n");
        }
    }
}