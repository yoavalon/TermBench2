c
#include <stdio.h>
#include <string.h>

#define SIZE 31
#define RULE_NUMBER 30
#define STEPS 10

typedef struct {
    int size;
    int rules[8];
    int state[SIZE];
} CellularAutomaton;

void CellularAutomaton_init(CellularAutomaton *ca, int size, int *rules) {
    ca->size = size;
    for (int i = 0; i < 8; i++) {
        ca->rules[i] = rules[i];
    }
    for (int i = 0; i < size; i++) {
        ca->state[i] = 0;
    }
}

void CellularAutomaton_update(CellularAutomaton *ca) {
    int new_state[SIZE];
    for (int i = 0; i < ca->size; i++) {
        int left = ca->state[(i - 1 + ca->size) % ca->size];
        int right = ca->state[(i + 1) % ca->size];
        int neighborhood = (left << 2) | (ca->state[i] << 1) | right;
        new_state[i] = ca->rules[neighborhood];
    }
    for (int i = 0; i < ca->size; i++) {
        ca->state[i] = new_state[i];
    }
}

void CellularAutomaton_display(CellularAutomaton *ca, char *buffer) {
    for (int i = 0; i < ca->size; i++) {
        buffer[i] = '0' + ca->state[i];
    }
    buffer[ca->size] = '\0';
}

void generate_rules(int rule_number, int *rules) {
    for (int i = 0; i < 8; i++) {
        int neighborhood = (i / 4) * 4 + (i / 2 % 2) * 2 + (i % 2);
        rules[neighborhood] = (rule_number >> i) & 1;
    }
}

void simulate_automaton(int size, int rule_number, int steps) {
    CellularAutomaton ca;
    int rules[8];
    generate_rules(rule_number, rules);
    CellularAutomaton_init(&ca, size, rules);
    ca.state[size / 2] = 1;
    char buffer[SIZE + 1];
    for (int step = 0; step < steps; step++) {
        CellularAutomaton_display(&ca, buffer);
        printf("%s\n", buffer);
        CellularAutomaton_update(&ca);
    }
}

int main() {
    simulate_automaton(SIZE, RULE_NUMBER, STEPS);
    return 0;
}