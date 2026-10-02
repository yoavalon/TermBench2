#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int rule;
    int* state;
} CellularAutomata;

CellularAutomata* CellularAutomata_init(int size, int rule) {
    CellularAutomata* ca = (CellularAutomata*)malloc(sizeof(CellularAutomata));
    ca->size = size;
    ca->rule = rule;
    ca->state = (int*)calloc(size, sizeof(int));
    ca->state[size / 2] = 1;
    return ca;
}

int CellularAutomata_apply_rule(CellularAutomata* ca, int left, int center, int right) {
    int index = 4 * left + 2 * center + right;
    return (ca->rule >> index) & 1;
}

void CellularAutomata_next_generation(CellularAutomata* ca) {
    int* new_state = (int*)calloc(ca->size, sizeof(int));
    for (int i = 0; i < ca->size; i++) {
        int left = ca->state[(i - 1 + ca->size) % ca->size];
        int center = ca->state[i];
        int right = ca->state[(i + 1) % ca->size];
        new_state[i] = CellularAutomata_apply_rule(ca, left, center, right);
    }
    free(ca->state);
    ca->state = new_state;
}

int** CellularAutomata_run(CellularAutomata* ca, int steps) {
    int** results = (int**)malloc(steps * sizeof(int*));
    for (int i = 0; i < steps; i++) {
        results[i] = (int*)malloc(ca->size * sizeof(int));
        for (int j = 0; j < ca->size; j++) {
            results[i][j] = ca->state[j];
        }
        CellularAutomata_next_generation(ca);
    }
    return results;
}

void free_sequence(int** sequence, int steps) {
    for (int i = 0; i < steps; i++) {
        free(sequence[i]);
    }
    free(sequence);
}

int** generate_sequence(int size, int rule, int steps) {
    CellularAutomata* ca = CellularAutomata_init(size, rule);
    int** sequence = CellularAutomata_run(ca, steps);
    free(ca->state);
    free(ca);
    return sequence;
}

void display_sequence(int** sequence, int size, int steps) {
    for (int i = 0; i < steps; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", sequence[i][j] ? '1' : '0');
        }
        printf("\n");
    }
}

int main() {
    int size = 31;
    int rule = 30;
    int steps = 10;
    int** sequence = generate_sequence(size, rule, steps);
    display_sequence(sequence, size, steps);
    free_sequence(sequence, steps);
    return 0;
}