#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>> cellular_automata(int n, int m, int steps) {
    std::srand(std::time(0));
    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            grid[i][j] = std::rand() % 2;
        }
    }
    for (int step = 0; step < steps; ++step) {
        std::vector<std::vector<int>> new_grid(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int neighbors = 0;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            neighbors += grid[ni][nj];
                        }
                    }
                }
                new_grid[i][j] = (neighbors == 3) || (neighbors == 2 && grid[i][j]) ? 1 : 0;
            }
        }
        grid = new_grid;
    }
    return grid;
}

int main() {
    std::vector<std::vector<int>> result = cellular_automata(10, 10, 5);
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}