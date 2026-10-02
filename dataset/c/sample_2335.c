#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    double value;
    struct Node* next;
} Node;

typedef struct Ledger {
    Node* head;
} Ledger;

typedef struct ConsensusMechanism {
    Ledger* ledger;
} ConsensusMechanism;

void Node_init(Node* self, double value) {
    self->value = value;
    self->next = NULL;
}

void Ledger_init(Ledger* self) {
    self->head = NULL;
}

void Ledger_append(Ledger* self, double value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node_init(new_node, value);
    if (!self->head) {
        self->head = new_node;
    } else {
        Node* current = self->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

double Ledger_calculate_consensus(Ledger* self) {
    Node* current = self->head;
    double total = 0;
    int count = 0;
    while (current) {
        total += current->value;
        count += 1;
        current = current->next;
    }
    if (count > 0) {
        return total / count;
    }
    return 0;
}

void ConsensusMechanism_init(ConsensusMechanism* self, Ledger* ledger) {
    self->ledger = ledger;
}

void ConsensusMechanism_update_ledger(ConsensusMechanism* self, double new_value) {
    Ledger_append(self->ledger, new_value);
}

void ConsensusMechanism_check_consensus(ConsensusMechanism* self) {
    while (1) {
        double consensus_value = Ledger_calculate_consensus(self->ledger);
        if (consensus_value > 0.5) {
            printf("Consensus reached: %f\n", consensus_value);
        } else {
            printf("Updating ledger with new value...\n");
            ConsensusMechanism_update_ledger(self, (double)rand() / RAND_MAX);
        }
    }
}

int main() {
    srand(time(NULL));
    Ledger ledger;
    Ledger_init(&ledger);
    ConsensusMechanism mechanism;
    ConsensusMechanism_init(&mechanism, &ledger);
    ConsensusMechanism_check_consensus(&mechanism);
    return 0;
}