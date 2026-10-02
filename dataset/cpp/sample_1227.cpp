#include <vector>
#include <iostream>

std::vector<std::vector<int>> cellular_automata(int size, int steps) {
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    for (int step = 0; step < steps; ++step) {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = 0;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                    }
                }
                neighbors -= grid[i][j];
                new_grid[i][j] = (neighbors == 3) || (grid[i][j] && neighbors == 2) ? 1 : 0;
            }
        }
        grid = new_grid;
    }
    return grid;
}

int main() {
    std::vector<std::vector<int>> result = cellular_automata(10, 5);
    for (const auto& row : result) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}