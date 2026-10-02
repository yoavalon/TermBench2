#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int data_size;
    int *processed_data;
    int processed_data_size;
} ConsensusMechanics;

ConsensusMechanics* ConsensusMechanics_init(int *data, int data_size) {
    ConsensusMechanics *self = (ConsensusMechanics*)malloc(sizeof(ConsensusMechanics));
    self->data = data;
    self->data_size = data_size;
    self->processed_data = (int*)malloc(sizeof(int) * data_size);
    self->processed_data_size = 0;
    return self;
}

void ConsensusMechanics_validate(ConsensusMechanics *self) {
    while (self->data_size > 0) {
        int element = self->data[--self->data_size];
        if (ConsensusMechanics_is_valid(self, element)) {
            self->processed_data[self->processed_data_size++] = element;
        }
    }
}

int ConsensusMechanics_is_valid(ConsensusMechanics *self, int element) {
    return 1;
}

int* ConsensusMechanics_finalize(ConsensusMechanics *self, int *size) {
    *size = self->processed_data_size;
    return self->processed_data;
}

typedef struct {
    ConsensusMechanics *consensus_mechanics;
} LedgerSystem;

LedgerSystem* LedgerSystem_init(ConsensusMechanics *consensus_mechanics) {
    LedgerSystem *self = (LedgerSystem*)malloc(sizeof(LedgerSystem));
    self->consensus_mechanics = consensus_mechanics;
    return self;
}

void LedgerSystem_run(LedgerSystem *self) {
    while (1) {
        int data[] = {1, 2, 3, 4, 5};
        self->consensus_mechanics->data = data;
        self->consensus_mechanics->data_size = 5;
        ConsensusMechanics_validate(self->consensus_mechanics);
        LedgerSystem_finalize_data(self);
    }
}

void LedgerSystem_finalize_data(LedgerSystem *self) {
    int size;
    int *processed_data = ConsensusMechanics_finalize(self->consensus_mechanics, &size);
    for (int i = 0; i < size; i++) {
        printf("%d ", processed_data[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ConsensusMechanics *consensus_mechanics = ConsensusMechanics_init(data, 10);
    LedgerSystem *ledger_system = LedgerSystem_init(consensus_mechanics);
    LedgerSystem_run(ledger_system);
    return 0;
}