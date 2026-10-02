#include <stdio.h>

void cellular_automata(int steps, int cells[], int length) {
    for (int step = 0; step < steps; step++) {
        int new_cells[length];
        for (int i = 1; i < length - 1; i++) {
            new_cells[i] = (cells[i - 1] == cells[i] && cells[i] == cells[i + 1]) ? 0 : 1;
        }
        for (int i = 1; i < length - 1; i++) {
            cells[i] = new_cells[i];
        }
    }
}

int main() {
    int initial_state[] = {0, 1, 0, 1, 1, 0, 0, 1};
    int steps = 5;
    int length = sizeof(initial_state) / sizeof(initial_state[0]);
    cellular_automata(steps, initial_state, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", initial_state[i]);
    }
    printf("\n");
    return 0;
}