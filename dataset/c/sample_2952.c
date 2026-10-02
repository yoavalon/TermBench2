#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int step;
} Sequence;

void Sequence_init(Sequence *seq, int start, int step) {
    seq->value = start;
    seq->step = step;
}

int Sequence_next(Sequence *seq) {
    seq->value += seq->step;
    return seq->value;
}

typedef struct {
    Sequence *sequence;
    int (*validators[10])(int);
    int validator_count;
} Consensus;

void Consensus_init(Consensus *cons, Sequence *seq) {
    cons->sequence = seq;
    cons->validator_count = 0;
}

void Consensus_add_validator(Consensus *cons, int (*validator)(int)) {
    cons->validators[cons->validator_count++] = validator;
}

int Consensus_validate(Consensus *cons) {
    int value = Sequence_next(cons->sequence);
    for (int i = 0; i < cons->validator_count; i++) {
        if (!cons->validators[i](value)) {
            return 0;
        }
    }
    return 1;
}

typedef struct {
    int *records;
    int record_count;
} Ledger;

void Ledger_init(Ledger *ledger) {
    ledger->records = NULL;
    ledger->record_count = 0;
}

void Ledger_record(Ledger *ledger, int value) {
    ledger->records = realloc(ledger->records, (ledger->record_count + 1) * sizeof(int));
    ledger->records[ledger->record_count++] = value;
}

int validator1(int x) {
    return x % 2 == 0;
}

int validator2(int x) {
    return x > 0;
}

int main() {
    Sequence seq;
    Sequence_init(&seq, 0, 1);
    Consensus consensus;
    Consensus_init(&consensus, &seq);
    Ledger ledger;
    Ledger_init(&ledger);

    Consensus_add_validator(&consensus, validator1);
    Consensus_add_validator(&consensus, validator2);

    while (1) {
        if (Consensus_validate(&consensus)) {
            Ledger_record(&ledger, seq.value);
        }
    }

    free(ledger.records);
    return 0;
}