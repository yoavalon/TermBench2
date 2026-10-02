#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int length;
    int *sequence;
} SequenceGenerator;

typedef struct {
    int *sequence;
    int *consolidated;
} ConsensusMechanic;

void SequenceGenerator_init(SequenceGenerator *self, int length) {
    self->length = length;
    self->sequence = (int *)malloc(length * sizeof(int));
}

void SequenceGenerator_generate_sequence(SequenceGenerator *self) {
    for (int i = 0; i < self->length; i++) {
        self->sequence[i] = self->calculate_value(i);
    }
}

int SequenceGenerator_calculate_value(SequenceGenerator *self, int index) {
    if (index % 2 == 0) {
        return index * index;
    } else {
        return 1 << index;
    }
}

void ConsensusMechanic_init(ConsensusMechanic *self, int *sequence) {
    self->sequence = sequence;
    self->consolidated = (int *)malloc(self->sequence[0] * sizeof(int));
}

void ConsensusMechanic_apply_consensus(ConsensusMechanic *self) {
    for (int i = 0; i < self->sequence[0]; i++) {
        self->consolidated[i] = self->validate_value(self->sequence[i]);
    }
}

int ConsensusMechanic_validate_value(ConsensusMechanic *self, int value) {
    if (value > 10) {
        return value - 5;
    } else {
        return value * 2;
    }
}

void main() {
    int length = 20;
    SequenceGenerator generator;
    SequenceGenerator_init(&generator, length);
    SequenceGenerator_generate_sequence(&generator);
    ConsensusMechanic mechanic;
    ConsensusMechanic_init(&mechanic, generator.sequence);
    ConsensusMechanic_apply_consensus(&mechanic);
    for (int i = 0; i < generator.length; i++) {
        printf("%d ", mechanic.consolidated[i]);
    }
    printf("\n");
}