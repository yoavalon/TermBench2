#include <vector>

std::vector<std::vector<int>> cellular_automata(int n, int m) {
    std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));
    while (true) {
        std::vector<std::vector<int>> new_grid(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int state = grid[i][j];
                int neighbors = 0;
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                neighbors -= state;
                new_grid[i][j] = (neighbors == 3 || (state && neighbors == 2)) ? 1 : 0;
            }
        }
        grid = new_grid;
    }
}

int main() {
    cellular_automata(10, 10);
    return 0;
}