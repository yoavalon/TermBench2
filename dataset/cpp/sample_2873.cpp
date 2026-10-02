#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> new_grid(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = 0;
            for (int ni = -1; ni <= 1; ++ni) {
                for (int nj = -1; nj <= 1; ++nj) {
                    int ii = i + ni;
                    int jj = j + nj;
                    if (ii >= 0 && ii < rows && jj >= 0 && jj < cols) {
                        neighbors += grid[ii][jj];
                    }
                }
            }
            neighbors -= grid[i][j];
            new_grid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j])) ? 1 : 0;
        }
    }
    return new_grid;
}

void main() {
    int rows = 50;
    int cols = 50;
    std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));
    grid[25][25] = 1;
    while (true) {
        grid = update_grid(grid);
    }
}