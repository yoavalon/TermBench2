#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int rule[8];
    int *state;
} Automaton;

void Automaton_init(Automaton *self, int size, int rule) {
    self->size = size;
    self->state = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        self->state[i] = 0;
    }
    self->state[size / 2] = 1;
    for (int i = 0; i < 8; i++) {
        self->rule[i] = (rule >> i) & 1;
    }
}

void Automaton_evolve(Automaton *self) {
    int *new_state = (int *)malloc(self->size * sizeof(int));
    for (int i = 1; i < self->size - 1; i++) {
        int pattern = (self->state[i - 1] << 2) | (self->state[i] << 1) | self->state[i + 1];
        new_state[i] = self->rule[pattern];
    }
    free(self->state);
    self->state = new_state;
}

void Automaton_display(Automaton *self) {
    for (int i = 0; i < self->size; i++) {
        printf("%d", self->state[i]);
    }
    printf("\n");
}

void generate_rule(int number, int *rule) {
    for (int i = 0; i < 8; i++) {
        rule[i] = (number >> i) & 1;
    }
}

void main() {
    int size = 31;
    int rule_number = 30;
    int rule[8];
    generate_rule(rule_number, rule);
    Automaton automaton;
    Automaton_init(&automaton, size, rule);
    int iterations = 10;
    for (int i = 0; i < iterations; i++) {
        Automaton_display(&automaton);
        Automaton_evolve(&automaton);
    }
    free(automaton.state);
}