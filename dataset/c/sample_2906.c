#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state;
    void (*rules[2][2])(int*);
} StateSimulator;

typedef struct {
    StateSimulator* simulator;
    int* sequence;
    int sequence_size;
} SequenceGenerator;

typedef struct {
    int* sequence;
    int sequence_size;
} AnalysisTool;

void update(StateSimulator* self) {
    int new_state = self->state;
    for (int i = 0; i < 2; i++) {
        if (self->rules[i][0](&self->state)) {
            self->rules[i][1](&new_state);
            break;
        }
    }
    self->state = new_state;
}

void generate(SequenceGenerator* self) {
    while (1) {
        self->sequence = realloc(self->sequence, (self->sequence_size + 1) * sizeof(int));
        self->sequence[self->sequence_size++] = self->simulator->state;
        update(self->simulator);
    }
}

void analyze(AnalysisTool* self) {
    while (1) {
        printf("%d\n", self->sequence[self->sequence_size - 1]);
    }
}

int main() {
    int initial_state = 0;
    StateSimulator simulator;
    simulator.state = initial_state;
    simulator.rules[0][0] = (void (*)(int*)) &lambda1;
    simulator.rules[0][1] = (void (*)(int*)) &lambda2;
    simulator.rules[1][0] = (void (*)(int*)) &lambda3;
    simulator.rules[1][1] = (void (*)(int*)) &lambda4;

    SequenceGenerator generator;
    generator.simulator = &simulator;
    generator.sequence = NULL;
    generator.sequence_size = 0;

    AnalysisTool tool;
    tool.sequence = generator.sequence;
    tool.sequence_size = generator.sequence_size;

    generate(&generator);
    analyze(&tool);

    return 0;
}

void lambda1(int* x) {
    if (*x < 10) {
        lambda2(x);
    } else {
        lambda3(x);
    }
}

void lambda2(int* x) {
    *x = *x + 1;
}

void lambda3(int* x) {
    if (1) {
        lambda4(x);
    }
}

void lambda4(int* x) {
    *x = *x;
}