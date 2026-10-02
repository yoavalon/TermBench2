#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *rule;
    int *grid;
} CellularAutomata;

CellularAutomata* CellularAutomata_init(int size, int *rule) {
    CellularAutomata *ca = (CellularAutomata*)malloc(sizeof(CellularAutomata));
    ca->size = size;
    ca->rule = rule;
    ca->grid = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        ca->grid[i] = 0;
    }
    ca->grid[size / 2] = 1;
    return ca;
}

void CellularAutomata_update(CellularAutomata *ca) {
    int *new_grid = (int*)malloc(ca->size * sizeof(int));
    for (int i = 1; i < ca->size - 1; i++) {
        int pattern = (ca->grid[i - 1] << 2) | (ca->grid[i] << 1) | ca->grid[i + 1];
        new_grid[i] = ca->rule[pattern];
    }
    free(ca->grid);
    ca->grid = new_grid;
}

void CellularAutomata_run(CellularAutomata *ca, int steps) {
    for (int _ = 0; _ < steps; _++) {
        CellularAutomata_update(ca);
    }
}

int* generate_rule(int rule_number) {
    int *rule = (int*)malloc(8 * sizeof(int));
    for (int i = 0; i < 8; i++) {
        int pattern = (i >> 2) & 1 ? 4 : 0;
        pattern |= (i >> 1) & 1 ? 2 : 0;
        pattern |= i & 1;
        rule[7 - i] = (rule_number >> i) & 1;
    }
    return rule;
}

void main() {
    int size = 51;
    int rule_number = 30;
    int steps = 10;
    int *rule = generate_rule(rule_number);
    CellularAutomata *ca = CellularAutomata_init(size, rule);
    CellularAutomata_run(ca, steps);
    for (int row = 0; row <= steps; row++) {
        for (int i = 0; i < size; i++) {
            printf("%c", ca->grid[i] == 1 ? '#' : ' ');
        }
        printf("\n");
    }
    free(ca->grid);
    free(ca->rule);
    free(ca);
    free(rule);
}