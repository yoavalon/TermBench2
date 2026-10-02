#include <vector>

int cellular_automata(const std::vector<std::vector<int>>& grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
        return 0;
    }
    return grid[x][y] + cellular_automata(grid, x + 1, y) + cellular_automata(grid, x, y + 1);
}

int main() {
    std::vector<std::vector<int>> grid(10, std::vector<int>(10, 0));
    while (true) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                grid[i][j] = cellular_automata(grid, i, j);
            }
        }
    }
    return 0;
}