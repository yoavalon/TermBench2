#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **grid;
    int grid_size;
} FluidSimulator;

typedef struct {
    int (*apply)(void*, int, int);
} RuleSet;

int apply_rule(void *ruleset, int grid, int x, int y) {
    RuleSet *rules = (RuleSet *)ruleset;
    int neighbors = rules->count_neighbors(grid, x, y);
    return neighbors == 2 ? 1 : 0;
}

int count_neighbors(int *grid, int grid_size, int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if ((i >= 0 && i < grid_size) && (j >= 0 && j < grid_size) && !(i == x && j == y) && grid[i * grid_size + j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void update(FluidSimulator *simulator, RuleSet *rules) {
    int *new_grid = (int *)malloc(simulator->grid_size * simulator->grid_size * sizeof(int));
    for (int i = 0; i < simulator->grid_size; i++) {
        for (int j = 0; j < simulator->grid_size; j++) {
            new_grid[i * simulator->grid_size + j] = rules->apply(rules, simulator->grid, i, j);
        }
    }
    free(simulator->grid);
    simulator->grid = new_grid;
}

void display(FluidSimulator *simulator) {
    for (int i = 0; i < simulator->grid_size; i++) {
        for (int j = 0; j < simulator->grid_size; j++) {
            printf("%d ", simulator->grid[i * simulator->grid_size + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int grid_size = 10;
    RuleSet rules;
    rules.apply = apply_rule;
    rules.count_neighbors = count_neighbors;

    FluidSimulator simulator;
    simulator.grid_size = grid_size;
    simulator.grid = (int *)malloc(grid_size * grid_size * sizeof(int));
    for (int i = 0; i < grid_size * grid_size; i++) {
        simulator.grid[i] = 0;
    }
    simulator.grid[4 * grid_size + 4] = 1;
    simulator.grid[5 * grid_size + 4] = 1;
    simulator.grid[4 * grid_size + 5] = 1;

    while (1) {
        display(&simulator);
        update(&simulator, &rules);
    }

    free(simulator.grid);
    return 0;
}