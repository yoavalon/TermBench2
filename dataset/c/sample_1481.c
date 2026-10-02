#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* records;
    int size;
} Ledger;

void Ledger_init(Ledger* ledger) {
    ledger->records = NULL;
    ledger->size = 0;
}

void Ledger_add_record(Ledger* ledger, int record) {
    ledger->records = (int*)realloc(ledger->records, (ledger->size + 1) * sizeof(int));
    ledger->records[ledger->size++] = record;
}

int* Ledger_get_records(Ledger* ledger) {
    return ledger->records;
}

typedef struct {
    Ledger* ledger;
    int (*validators[10])(Ledger*);
    int validator_count;
} Consensus;

void Consensus_init(Consensus* consensus, Ledger* ledger) {
    consensus->ledger = ledger;
    consensus->validator_count = 0;
}

void Consensus_add_validator(Consensus* consensus, int (*validator)(Ledger*)) {
    consensus->validators[consensus->validator_count++] = validator;
}

int Consensus_validate(Consensus* consensus) {
    for (int i = 0; i < consensus->validator_count; i++) {
        if (!consensus->validators[i](consensus->ledger)) {
            return 0;
        }
    }
    return 1;
}

typedef struct {
    int (*rule)(Ledger*);
} Validator;

int Validator_call(Validator* validator, Ledger* ledger) {
    return validator->rule(ledger);
}

int data_mutation_rule(Ledger* ledger) {
    int* records = Ledger_get_records(ledger);
    for (int i = 0; i < ledger->size; i++) {
        records[i] *= 2;
    }
    return 1;
}

int main() {
    Ledger ledger;
    Ledger_init(&ledger);
    Ledger_add_record(&ledger, 1);
    Ledger_add_record(&ledger, 2);
    Ledger_add_record(&ledger, 3);

    Validator validator1;
    validator1.rule = (int (*)(Ledger*))data_mutation_rule;

    Validator validator2;
    validator2.rule = (int (*)(Ledger*))data_mutation_rule;

    Consensus consensus;
    Consensus_init(&consensus, &ledger);
    Consensus_add_validator(&consensus, (int (*)(Ledger*))(validator1.rule));
    Consensus_add_validator(&consensus, (int (*)(Ledger*))(validator2.rule));

    if (Consensus_validate(&consensus)) {
        int* mutated_data = Ledger_get_records(&ledger);
        for (int i = 0; i < ledger.size; i++) {
            printf("%d ", mutated_data[i]);
        }
        printf("\n");
    } else {
        printf("Validation failed.\n");
    }

    free(ledger.records);
    return 0;
}