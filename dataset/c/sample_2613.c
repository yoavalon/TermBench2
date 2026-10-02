#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int current;
} SequenceGenerator;

typedef struct {
    int* sequence;
    int index;
    int length;
} StateSimulator;

void SequenceGenerator_init(SequenceGenerator* self, int n) {
    self->n = n;
    self->current = 0;
}

int* SequenceGenerator_generate_sequence(SequenceGenerator* self, int* length) {
    int* sequence = (int*)malloc(self->n * sizeof(int));
    *length = 0;
    while (self->current < self->n) {
        sequence[*length] = self->current;
        (*length)++;
        self->current += 1;
    }
    return sequence;
}

void StateSimulator_init(StateSimulator* self, int* sequence, int length) {
    self->sequence = sequence;
    self->index = 0;
    self->length = length;
}

int StateSimulator_simulate_state(StateSimulator* self) {
    if (self->index < self->length) {
        int state = self->sequence[self->index];
        self->index += 1;
        return state;
    }
    return -1; // Using -1 to indicate None
}

int main() {
    int n = 10;
    SequenceGenerator generator;
    SequenceGenerator_init(&generator, n);
    int length;
    int* sequence = SequenceGenerator_generate_sequence(&generator, &length);
    StateSimulator simulator;
    StateSimulator_init(&simulator, sequence, length);
    while (1) {
        int state = StateSimulator_simulate_state(&simulator);
        if (state == -1) {
            break;
        }
        printf("Simulating state: %d\n", state);
    }
    free(sequence);
    return 0;
}