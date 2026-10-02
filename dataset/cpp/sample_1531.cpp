#include <iostream>
#include <vector>

void cellular_automata(int width, int height) {
    std::vector<std::vector<int>> grid(height, std::vector<int>(width, 0));
    while (true) {
        std::vector<std::vector<int>> new_grid = grid;
        for (int i = 1; i < height - 1; ++i) {
            for (int j = 1; j < width - 1; ++j) {
                int neighbors = 0;
                for (int ni = i - 1; ni <= i + 1; ++ni) {
                    for (int nj = j - 1; nj <= j + 1; ++nj) {
                        neighbors += grid[ni][nj];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (!grid[i][j] && neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }
}

int main() {
    cellular_automata(50, 50);
    return 0;
}