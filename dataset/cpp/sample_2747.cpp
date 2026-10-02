#include <vector>
#include <iostream>

void cellular_automata(int x, int y, int steps) {
    std::vector<std::vector<int>> grid(y, std::vector<int>(x, 0));
    for (int _ = 0; _ < steps; ++_) {
        std::vector<std::vector<int>> new_grid(grid);
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                int neighbors = 0;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (i + di >= 0 && i + di < y && j + dj >= 0 && j + dj < x) {
                            neighbors += grid[i + di][j + dj];
                        }
                    }
                }
                neighbors -= grid[i][j];
                new_grid[i][j] = (neighbors == 3) || (neighbors == 2 && grid[i][j]) ? 1 : 0;
            }
        }
        grid = new_grid;
    }
}

int main() {
    cellular_automata(10, 10, 1000000);
    return 0;
}