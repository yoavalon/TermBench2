#include <stdio.h>

int update_grid(int *grid, int size, int (*rule)(int, int, int)) {
    int new_grid[size];
    for (int i = 0; i < size; i++) {
        int left = grid[(i - 1 + size) % size];
        int right = grid[(i + 1) % size];
        new_grid[i] = rule(left, grid[i], right);
    }
    for (int i = 0; i < size; i++) {
        grid[i] = new_grid[i];
    }
    return 0;
}

int *cellular_automaton(int steps, int *initial_state, int size, int (*rule)(int, int, int)) {
    int *current_state = initial_state;
    for (int _ = 0; _ < steps; _++) {
        update_grid(current_state, size, rule);
    }
    return current_state;
}

int rule_conway(int left, int center, int right) {
    int neighbor_count = left + center + right;
    if (center == 1) {
        return (neighbor_count == 2 || neighbor_count == 3) ? 1 : 0;
    } else {
        return (neighbor_count == 3) ? 1 : 0;
    }
}

int main() {
    int initial_state[] = {0, 1, 0, 1, 1, 0, 1, 0};
    int steps = 5;
    int size = sizeof(initial_state) / sizeof(initial_state[0]);
    int *final_state = cellular_automaton(steps, initial_state, size, rule_conway);
    for (int i = 0; i < size; i++) {
        printf("%d ", final_state[i]);
    }
    return 0;
}