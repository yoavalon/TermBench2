#include <stdio.h>

void update_cells(int state[5][5], int new_state[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int neighbors = 0;
            for (int x = fmax(0, i - 1); x < fmin(5, i + 2); x++) {
                for (int y = fmax(0, j - 1); y < fmin(5, j + 2); y++) {
                    if (x != i || y != j) {
                        neighbors += state[x][y];
                    }
                }
            }
            new_state[i][j] = (neighbors == 3) || (neighbors == 2 && state[i][j]) ? 1 : 0;
        }
    }
}

void simulate(int state[5][5]) {
    while (1) {
        int new_state[5][5];
        update_cells(state, new_state);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%c", new_state[i][j] ? '█' : ' ');
            }
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                state[i][j] = new_state[i][j];
            }
        }
    }
}

void main() {
    int initial_state[5][5] = {{0, 0, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}};
    simulate(initial_state);
}