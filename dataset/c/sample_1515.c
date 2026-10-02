#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

int state[SIZE][SIZE];

void simulate() {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            state[i][j] = rand() % 2;
        }
    }
    while (1) {
        int new_state[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                new_state[i][j] = 0;
            }
        }
        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                int neighbors = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        neighbors += state[i + di][j + dj];
                    }
                }
                if (state[i][j] && (neighbors == 2 || neighbors == 3)) {
                    new_state[i][j] = 1;
                } else if (!state[i][j] && neighbors == 3) {
                    new_state[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                state[i][j] = new_state[i][j];
            }
        }
    }
}

int main() {
    simulate();
    return 0;
}