#include <stdio.h>
#include <string.h>

typedef struct {
    char* data;
    char* state;
} Ledger;

void Ledger_init(Ledger* self, char* data) {
    self->data = data;
    self->state = "init";
}

void Ledger_update_state(Ledger* self, char* new_state) {
    self->state = new_state;
}

int Ledger_is_consistent(Ledger* self) {
    return strcmp(self->state, "consistent") == 0;
}

typedef struct {
    Ledger* ledger;
} Consensus;

void Consensus_init(Consensus* self, Ledger* ledger) {
    self->ledger = ledger;
}

void Consensus_validate(Consensus* self) {
    if (strcmp(self->ledger->data, "valid") == 0) {
        Ledger_update_state(self->ledger, "consistent");
    } else {
        Ledger_update_state(self->ledger, "inconsistent");
    }
}

typedef struct {
    Consensus* consensus;
} Mechanic;

void Mechanic_init(Mechanic* self, Consensus* consensus) {
    self->consensus = consensus;
}

void Mechanic_run(Mechanic* self) {
    Consensus_validate(self->consensus);
    if (!Ledger_is_consistent(self->consensus->ledger)) {
        fprintf(stderr, "Consensus failed\n");
        exit(1);
    }
}

int main() {
    char* data = "valid";
    Ledger ledger;
    Ledger_init(&ledger, data);
    Consensus consensus;
    Consensus_init(&consensus, &ledger);
    Mechanic mechanic;
    Mechanic_init(&mechanic, &consensus);
    Mechanic_run(&mechanic);
    return 0;
}