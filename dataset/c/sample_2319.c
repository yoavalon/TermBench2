#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int precision;
    double balance;
    double* transactions;
    int transaction_count;
} Ledger;

void Ledger_init(Ledger* self, int precision) {
    self->precision = precision;
    self->balance = 0.0;
    self->transactions = (double*)malloc(0);
    self->transaction_count = 0;
}

void Ledger_record_transaction(Ledger* self, double amount) {
    self->transactions = (double*)realloc(self->transactions, (self->transaction_count + 1) * sizeof(double));
    self->transactions[self->transaction_count++] = amount;
    self->balance += amount;
    self->balance = round(self->balance * pow(10, self->precision)) / pow(10, self->precision);
}

double Ledger_get_balance(Ledger* self) {
    return self->balance;
}

int Ledger_total_transactions(Ledger* self) {
    return self->transaction_count;
}

typedef struct {
    Ledger* ledger;
    int validator_count;
} ConsensusMechanism;

void ConsensusMechanism_init(ConsensusMechanism* self, Ledger* ledger) {
    self->ledger = ledger;
    self->validator_count = 0;
}

void ConsensusMechanism_add_validator(ConsensusMechanism* self) {
    self->validator_count += 1;
}

int ConsensusMechanism_validate_transaction(ConsensusMechanism* self, double amount) {
    if (self->validator_count > 0) {
        Ledger_record_transaction(self->ledger, amount);
        return 1;
    }
    return 0;
}

int ConsensusMechanism_get_validator_count(ConsensusMechanism* self) {
    return self->validator_count;
}

typedef struct {
    Ledger ledger;
    ConsensusMechanism consensus;
} Network;

void Network_init(Network* self, int precision) {
    Ledger_init(&self->ledger, precision);
    ConsensusMechanism_init(&self->consensus, &self->ledger);
}

void Network_run(Network* self) {
    ConsensusMechanism_add_validator(&self->consensus);
    while (1) {
        double amount = 0.1;
        if (ConsensusMechanism_validate_transaction(&self->consensus, amount)) {
            printf("%f\n", Ledger_get_balance(&self->ledger));
        } else {
            printf("Validation failed\n");
        }
    }
}

int main() {
    Network network;
    Network_init(&network, 10);
    Network_run(&network);
    return 0;
}