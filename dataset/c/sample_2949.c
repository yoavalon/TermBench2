#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct SequenceGenerator {
    int current;
    int step;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int step) {
    self->current = start;
    self->step = step;
}

int SequenceGenerator_next(SequenceGenerator *self) {
    int result = self->current;
    self->current += self->step;
    return result;
}

typedef struct Validator {
    bool (*func)(int);
} Validator;

typedef struct ConsensusMechanics {
    SequenceGenerator *sequence;
    Validator *validators;
    int validator_count;
    double threshold;
} ConsensusMechanics;

void ConsensusMechanics_init(ConsensusMechanics *self, SequenceGenerator *sequence) {
    self->sequence = sequence;
    self->validators = NULL;
    self->validator_count = 0;
    self->threshold = 0.5;
}

void ConsensusMechanics_add_validator(ConsensusMechanics *self, bool (*validator)(int)) {
    self->validators = realloc(self->validators, (self->validator_count + 1) * sizeof(Validator));
    self->validators[self->validator_count].func = validator;
    self->validator_count++;
}

bool ConsensusMechanics_validate(ConsensusMechanics *self, int value) {
    for (int i = 0; i < self->validator_count; i++) {
        if (!self->validators[i].func(value)) {
            return false;
        }
    }
    return true;
}

void ConsensusMechanics_run(ConsensusMechanics *self) {
    while (true) {
        int value = SequenceGenerator_next(self->sequence);
        if (ConsensusMechanics_validate(self, value)) {
            printf("Consensus reached on value: %d\n", value);
        }
    }
}

bool validator_one(int value) {
    return value % 2 == 0;
}

bool validator_two(int value) {
    return value > 10;
}

int main() {
    SequenceGenerator sequence;
    SequenceGenerator_init(&sequence, 5, 3);

    ConsensusMechanics mechanics;
    ConsensusMechanics_init(&mechanics, &sequence);
    ConsensusMechanics_add_validator(&mechanics, validator_one);
    ConsensusMechanics_add_validator(&mechanics, validator_two);

    ConsensusMechanics_run(&mechanics);
    return 0;
}