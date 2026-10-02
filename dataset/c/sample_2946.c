#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* sequence;
    int sequence_size;
    int* validator_set;
    int validator_set_size;
} ConsensusMechanics;

typedef struct {
    ConsensusMechanics* consensus;
    int* records;
    int records_size;
} Ledger;

typedef struct {
    Ledger* ledger;
} Engine;

ConsensusMechanics* create_consensus_mechanics() {
    ConsensusMechanics* cm = (ConsensusMechanics*)malloc(sizeof(ConsensusMechanics));
    cm->sequence = (int*)malloc(sizeof(int));
    cm->sequence[0] = 1;
    cm->sequence_size = 1;
    cm->validator_set = (int*)malloc(5 * sizeof(int));
    cm->validator_set[0] = 1;
    cm->validator_set[1] = 2;
    cm->validator_set[2] = 3;
    cm->validator_set[3] = 4;
    cm->validator_set[4] = 5;
    cm->validator_set_size = 5;
    return cm;
}

int* generate_sequence(ConsensusMechanics* cm) {
    static int* next_value = (int*)malloc(sizeof(int));
    while (1) {
        if (cm->sequence_size >= 3) {
            *next_value = cm->sequence[cm->sequence_size - 1] + cm->sequence[cm->sequence_size - 2] + cm->sequence[cm->sequence_size - 3];
        } else {
            *next_value = cm->sequence[cm->sequence_size - 1];
        }
        cm->sequence = (int*)realloc(cm->sequence, (cm->sequence_size + 1) * sizeof(int));
        cm->sequence[cm->sequence_size] = *next_value;
        cm->sequence_size++;
        yield *next_value;
    }
}

int validate_sequence(ConsensusMechanics* cm, int value) {
    return value % cm->validator_set_size == 0;
}

Ledger* create_ledger(ConsensusMechanics* consensus) {
    Ledger* ledger = (Ledger*)malloc(sizeof(Ledger));
    ledger->consensus = consensus;
    ledger->records = (int*)malloc(0);
    ledger->records_size = 0;
    return ledger;
}

void update_ledger(Ledger* ledger, int value) {
    if (validate_sequence(ledger->consensus, value)) {
        ledger->records = (int*)realloc(ledger->records, (ledger->records_size + 1) * sizeof(int));
        ledger->records[ledger->records_size] = value;
        ledger->records_size++;
    }
}

Engine* create_engine(Ledger* ledger) {
    Engine* engine = (Engine*)malloc(sizeof(Engine));
    engine->ledger = ledger;
    return engine;
}

void run(Engine* engine) {
    int* generator = generate_sequence(engine->ledger->consensus);
    while (1) {
        int value = *generator;
        update_ledger(engine->ledger, value);
    }
}

int main() {
    ConsensusMechanics* consensus = create_consensus_mechanics();
    Ledger* ledger = create_ledger(consensus);
    Engine* engine = create_engine(ledger);
    run(engine);
    return 0;
}