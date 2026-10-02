#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int **grid;
    char *boundary;
} Grid;

void init_grid(Grid *g, int size, char *boundary) {
    g->size = size;
    g->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        g->grid[i] = (int *)calloc(size, sizeof(int));
    }
    g->boundary = boundary;
}

void update(Grid *g) {
    int **new_grid = (int **)malloc(g->size * sizeof(int *));
    for (int i = 0; i < g->size; i++) {
        new_grid[i] = (int *)calloc(g->size, sizeof(int));
    }
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            int *neighbors = boundary_condition(g, i, j);
            int count = 0;
            for (int k = 0; k < 8; k++) {
                count += neighbors[k];
            }
            new_grid[i][j] = apply_rules(count, g->grid[i][j]);
            free(neighbors);
        }
    }
    for (int i = 0; i < g->size; i++) {
        free(g->grid[i]);
    }
    free(g->grid);
    g->grid = new_grid;
}

int *boundary_condition(Grid *g, int x, int y) {
    int *neighbors = (int *)malloc(8 * sizeof(int));
    int index = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            int nx = x + dx;
            int ny = y + dy;
            if (strcmp(g->boundary, "fixed") == 0) {
                if (0 <= nx && nx < g->size && 0 <= ny && ny < g->size) {
                    neighbors[index++] = g->grid[nx][ny];
                } else {
                    neighbors[index++] = 0;
                }
            } else if (strcmp(g->boundary, "periodic") == 0) {
                neighbors[index++] = g->grid[(nx + g->size) % g->size][(ny + g->size) % g->size];
            }
        }
    }
    return neighbors;
}

int apply_rules(int count, int current) {
    if (current == 1) {
        if (count < 2 || count > 3) {
            return 0;
        }
        return 1;
    } else {
        if (count == 3) {
            return 1;
        }
        return 0;
    }
}

void main() {
    int size = 10;
    char *boundary = "periodic";
    Grid grid;
    init_grid(&grid, size, boundary);
    int steps = 50;
    for (int _ = 0; _ < steps; _++) {
        update(&grid);
    }
    for (int i = 0; i < grid.size; i++) {
        free(grid.grid[i]);
    }
    free(grid.grid);
}