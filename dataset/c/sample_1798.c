#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Ledger {
    Node* head;
} Ledger;

void Ledger_init(Ledger* self) {
    self->head = NULL;
}

void Ledger_append(Ledger* self, int value) {
    if (!self->head) {
        self->head = (Node*)malloc(sizeof(Node));
        self->head->value = value;
        self->head->next = NULL;
    } else {
        Node* current = self->head;
        while (current->next) {
            current = current->next;
        }
        current->next = (Node*)malloc(sizeof(Node));
        current->next->value = value;
        current->next->next = NULL;
    }
}

int Ledger_verify_consensus(Ledger* self) {
    Node* current = self->head;
    while (current) {
        if (!Ledger_is_valid(self, current->value)) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

int Ledger_is_valid(Ledger* self, int value) {
    return value % 2 == 0;
}

typedef struct ConsensusMechanism {
    Ledger* ledger;
} ConsensusMechanism;

void ConsensusMechanism_init(ConsensusMechanism* self, Ledger* ledger) {
    self->ledger = ledger;
}

void ConsensusMechanism_run(ConsensusMechanism* self) {
    while (1) {
        if (!Ledger_verify_consensus(self->ledger)) {
            ConsensusMechanism_correct_mutation(self);
        }
        Ledger_append(self->ledger, ConsensusMechanism_generate_new_value(self));
    }
}

void ConsensusMechanism_correct_mutation(ConsensusMechanism* self) {
    Node* current = self->ledger->head;
    while (current) {
        if (!Ledger_is_valid(self->ledger, current->value)) {
            current->value = ConsensusMechanism_correct_value(self, current->value);
        }
        current = current->next;
    }
}

int ConsensusMechanism_generate_new_value(ConsensusMechanism* self) {
    return rand() % 101;
}

int ConsensusMechanism_correct_value(ConsensusMechanism* self, int value) {
    return value + 1;
}

void main() {
    Ledger ledger;
    Ledger_init(&ledger);
    ConsensusMechanism mechanism;
    ConsensusMechanism_init(&mechanism, &ledger);
    srand(time(NULL));
    ConsensusMechanism_run(&mechanism);
}