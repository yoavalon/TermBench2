#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void update(int* state, int* new_state, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            if (i > 0) neighbors += state[(i - 1) * cols + j];
            if (i < rows - 1) neighbors += state[(i + 1) * cols + j];
            if (j > 0) neighbors += state[i * cols + j - 1];
            if (j < cols - 1) neighbors += state[i * cols + j + 1];
            if (state[i * cols + j] == 1 && neighbors < 2) new_state[i * cols + j] = 0;
            else if (state[i * cols + j] == 1 && neighbors > 3) new_state[i * cols + j] = 0;
            else if (state[i * cols + j] == 0 && neighbors == 3) new_state[i * cols + j] = 1;
            else new_state[i * cols + j] = state[i * cols + j];
        }
    }
}

void simulate() {
    int rows = 20;
    int cols = 20;
    int* state = (int*)malloc(rows * cols * sizeof(int));
    int* new_state = (int*)malloc(rows * cols * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < rows * cols; i++) {
        state[i] = rand() % 2;
    }
    while (1) {
        update(state, new_state, rows, cols);
        int* temp = state;
        state = new_state;
        new_state = temp;
    }
    free(state);
    free(new_state);
}

int main() {
    simulate();
    return 0;
}