#include <iostream>
#include <vector>

std::vector<int> cellular_automata(int steps, std::vector<int> cells) {
    for (int _ = 0; _ < steps; ++_) {
        std::vector<int> new_cells;
        for (int i = 1; i < cells.size() - 1; ++i) {
            new_cells.push_back(cells[i - 1] == cells[i] && cells[i] == cells[i + 1] ? 0 : 1);
        }
        cells = new_cells;
    }
    return cells;
}

int main() {
    std::vector<int> initial_state = {0, 1, 0, 1, 1, 0, 0, 1};
    int steps = 5;
    std::vector<int> result = cellular_automata(steps, initial_state);
    for (int cell : result) {
        std::cout << cell << " ";
    }
    std::cout << std::endl;
    return 0;
}