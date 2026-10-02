#include <iostream>
#include <vector>

std::vector<int> update_grid(const std::vector<int>& grid, int (*rule)(int, int, int)) {
    int size = grid.size();
    std::vector<int> new_grid(size, 0);
    for (int i = 0; i < size; ++i) {
        int left = grid[(i - 1 + size) % size];
        int right = grid[(i + 1) % size];
        new_grid[i] = rule(left, grid[i], right);
    }
    return new_grid;
}

std::vector<int> cellular_automaton(int steps, const std::vector<int>& initial_state, int (*rule)(int, int, int)) {
    std::vector<int> current_state = initial_state;
    for (int _ = 0; _ < steps; ++_) {
        current_state = update_grid(current_state, rule);
    }
    return current_state;
}

int rule_conway(int left, int center, int right) {
    int neighbor_count = left + center + right;
    if (center == 1) {
        return neighbor_count == 2 || neighbor_count == 3 ? 1 : 0;
    } else {
        return neighbor_count == 3 ? 1 : 0;
    }
}

int main() {
    std::vector<int> initial_state = {0, 1, 0, 1, 1, 0, 1, 0};
    int steps = 5;
    std::vector<int> final_state = cellular_automaton(steps, initial_state, rule_conway);
    for (int cell : final_state) {
        std::cout << cell << " ";
    }
    std::cout << std::endl;
    return 0;
}