#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** grid;
    int size;
} Automata;

void Automata_init(Automata* self, int size) {
    self->size = size;
    self->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int*)calloc(size, sizeof(int));
    }
}

void Automata_update(Automata* self) {
    int** new_grid = (int**)malloc(self->size * sizeof(int*));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int*)calloc(self->size, sizeof(int));
    }
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            int neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int nx = i + di, ny = j + dj;
                    if (nx >= 0 && nx < self->size && ny >= 0 && ny < self->size) {
                        neighbors += self->grid[nx][ny];
                    }
                }
            }
            if (self->grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else if (self->grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = self->grid[i][j];
            }
        }
    }
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;
}

int Automata_count_neighbors(Automata* self, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int nx = x + i, ny = y + j;
            if (nx >= 0 && nx < self->size && ny >= 0 && ny < self->size) {
                count += self->grid[nx][ny];
            }
        }
    }
    return count;
}

void Automata_display(Automata* self) {
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            putchar(self->grid[i][j] ? '#' : ' ');
        }
        putchar('\n');
    }
}

void Automata_free(Automata* self) {
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
}

int main() {
    int size = 20;
    Automata automata;
    Automata_init(&automata, size);
    while (1) {
        Automata_display(&automata);
        Automata_update(&automata);
    }
    Automata_free(&automata);
    return 0;
}