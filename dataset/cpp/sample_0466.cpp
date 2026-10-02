cpp
#include <vector>

bool update_cell(std::vector<std::vector<int>>& grid, int i, int j, int size) {
    int neighbors = 0;
    for (int x = i - 1; x <= i + 1; ++x) {
        for (int y = j - 1; y <= j + 1; ++y) {
            if (x >= 0 && x < size && y >= 0 && y < size && (x != i || y != j)) {
                neighbors += grid[x][y];
            }
        }
    }
    return neighbors == 3 || (grid[i][j] && neighbors == 2);
}

std::vector<std::vector<int>> step(std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            new_grid[i][j] = update_cell(grid, i, j, size);
        }
    }
    return new_grid;
}

int main() {
    int size = 10;
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    grid[1][1] = 1;
    grid[2][2] = 1;
    grid[2][1] = 1;
    while (true) {
        grid = step(grid);
    }
    return 0;
}