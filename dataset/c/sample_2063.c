#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *data;
    double balance;
} Ledger;

void Ledger_init(Ledger *self, double *data) {
    self->data = data;
    self->balance = 0;
}

void Ledger_update_balance(Ledger *self, double amount) {
    self->balance += amount;
}

double Ledger_get_balance(Ledger *self) {
    return self->balance;
}

typedef struct {
    Ledger *ledger;
    double threshold;
} Consensus;

void Consensus_init(Consensus *self, Ledger *ledger) {
    self->ledger = ledger;
    self->threshold = 0.0001;
}

int Consensus_verify_transaction(Consensus *self, double amount) {
    if (fabs(amount) > self->threshold) {
        return 1;
    }
    return 0;
}

void Consensus_process_transactions(Consensus *self, double *transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        if (Consensus_verify_transaction(self, transactions[i])) {
            Ledger_update_balance(self->ledger, transactions[i]);
        }
    }
}

typedef struct {
    Ledger *ledger;
} Analysis;

void Analysis_init(Analysis *self, Ledger *ledger) {
    self->ledger = ledger;
}

double Analysis_calculate_precision_error(Analysis *self) {
    double balance = Ledger_get_balance(self->ledger);
    double error = balance - (int)balance;
    return error;
}

int main() {
    double data[] = {5e-05, -2e-05, 3e-05, 0.00015, -1e-05};
    Ledger ledger;
    Ledger_init(&ledger, data);
    Consensus consensus;
    Consensus_init(&consensus, &ledger);
    Analysis analysis;
    Analysis_init(&analysis, &ledger);
    double transactions[] = {5e-05, -2e-05, 3e-05, 0.00015, -1e-05};
    int num_transactions = sizeof(transactions) / sizeof(transactions[0]);
    Consensus_process_transactions(&consensus, transactions, num_transactions);
    double error = Analysis_calculate_precision_error(&analysis);
    printf("Floating point precision error: %f\n", error);
    return 0;
}