#include <iostream>
#include <vector>

void cellular_automata(int n) {
    std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));
    while (true) {
        std::vector<std::vector<int>> next_grid(n, std::vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int neighbors = 0;
                for (int x = -1; x <= 1; ++x) {
                    for (int y = -1; y <= 1; ++y) {
                        if ((x != 0 || y != 0)) {
                            neighbors += grid[(i + x + n) % n][(j + y + n) % n];
                        }
                    }
                }
                if (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) {
                    next_grid[i][j] = 1;
                }
            }
        }
        grid = next_grid;
    }
}

int main() {
    cellular_automata(10);
    return 0;
}