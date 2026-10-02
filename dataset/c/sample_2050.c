#include <stdio.h>

typedef struct {
    int nodes;
    double threshold;
    double *votes;
    char *state;
} ConsensusMechanism;

typedef struct {
    int length;
    double *data;
} Ledger;

ConsensusMechanism* ConsensusMechanism_new(int nodes, double threshold) {
    ConsensusMechanism *self = (ConsensusMechanism*)malloc(sizeof(ConsensusMechanism));
    self->nodes = nodes;
    self->threshold = threshold;
    self->votes = (double*)calloc(nodes, sizeof(double));
    self->state = "pending";
    return self;
}

void ConsensusMechanism_record_vote(ConsensusMechanism *self, int node_index, double vote) {
    if (node_index < self->nodes) {
        self->votes[node_index] = vote;
        ConsensusMechanism_check_consensus(self);
    }
}

void ConsensusMechanism_check_consensus(ConsensusMechanism *self) {
    double total = 0.0;
    for (int i = 0; i < self->nodes; i++) {
        total += self->votes[i];
    }
    if (total >= self->threshold) {
        self->state = "consensus";
    }
}

Ledger* Ledger_new(int length) {
    Ledger *self = (Ledger*)malloc(sizeof(Ledger));
    self->length = length;
    self->data = (double*)calloc(length, sizeof(double));
    return self;
}

void Ledger_update(Ledger *self, int index, double value) {
    if (index < self->length) {
        self->data[index] = value;
    }
}

int main() {
    int nodes = 5;
    double threshold = 3.0;
    ConsensusMechanism *mechanism = ConsensusMechanism_new(nodes, threshold);
    Ledger *ledger = Ledger_new(nodes);
    for (int i = 0; i < nodes; i++) {
        ConsensusMechanism_record_vote(mechanism, i, 1.0);
        Ledger_update(ledger, i, 1.0);
    }
    if (strcmp(mechanism->state, "consensus") == 0) {
        printf("Consensus reached.\n");
    } else {
        printf("Consensus not reached.\n");
    }
    free(mechanism->votes);
    free(mechanism);
    free(ledger->data);
    free(ledger);
    return 0;
}