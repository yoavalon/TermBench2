#include <vector>

std::vector<std::vector<int>> cellular_automata(int rows, int cols, int steps) {
    std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));
    for (int step = 0; step < steps; ++step) {
        std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int neighbors = 0;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx == 0 && dy == 0) continue;
                        neighbors += grid[(i + dx + rows) % rows][(j + dy + cols) % cols];
                    }
                }
                new_grid[i][j] = (neighbors == 3) ? 1 : grid[i][j];
            }
        }
        grid = new_grid;
    }
    return grid;
}

int main() {
    while (true) {
        cellular_automata(10, 10, 100);
    }
    return 0;
}