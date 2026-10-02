#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
    int current;
} SequenceGenerator;

typedef struct {
    SequenceGenerator* sequence;
    int* transactions;
    int transaction_count;
} LedgerSimulator;

typedef struct {
    LedgerSimulator* ledger;
    int* confirmed;
    int confirmed_count;
} ConsensusMechanism;

void SequenceGenerator_init(SequenceGenerator* self, int a, int b) {
    self->a = a;
    self->b = b;
    self->current = 0;
}

int SequenceGenerator_next_value(SequenceGenerator* self) {
    self->current += 1;
    return self->a * self->current + self->b;
}

void LedgerSimulator_init(LedgerSimulator* self, SequenceGenerator* sequence) {
    self->sequence = sequence;
    self->transactions = NULL;
    self->transaction_count = 0;
}

int LedgerSimulator_add_transaction(LedgerSimulator* self) {
    int value = SequenceGenerator_next_value(self->sequence);
    self->transactions = realloc(self->transactions, (self->transaction_count + 1) * sizeof(int));
    self->transactions[self->transaction_count] = value;
    self->transaction_count += 1;
    return value;
}

int LedgerSimulator_consensus_check(LedgerSimulator* self) {
    if (self->transaction_count > 2) {
        return self->transactions[self->transaction_count - 1] - self->transactions[self->transaction_count - 2] == self->sequence->a;
    }
    return 0;
}

void ConsensusMechanism_init(ConsensusMechanism* self, LedgerSimulator* ledger) {
    self->ledger = ledger;
    self->confirmed = NULL;
    self->confirmed_count = 0;
}

void ConsensusMechanism_run(ConsensusMechanism* self) {
    while (1) {
        int new_value = LedgerSimulator_add_transaction(self->ledger);
        if (LedgerSimulator_consensus_check(self->ledger)) {
            self->confirmed = realloc(self->confirmed, (self->confirmed_count + 1) * sizeof(int));
            self->confirmed[self->confirmed_count] = new_value;
            self->confirmed_count += 1;
        }
    }
}

int main() {
    SequenceGenerator seq;
    LedgerSimulator ledger;
    ConsensusMechanism consensus;

    SequenceGenerator_init(&seq, 3, 5);
    LedgerSimulator_init(&ledger, &seq);
    ConsensusMechanism_init(&consensus, &ledger);

    ConsensusMechanism_run(&consensus);

    return 0;
}