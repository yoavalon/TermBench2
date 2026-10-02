#include <iostream>
#include <vector>

int update_cell(std::vector<std::vector<int>>& grid, int x, int y, int width, int height) {
    int neighbors = 0;
    for (int i = std::max(0, x - 1); i < std::min(width, x + 2); ++i) {
        for (int j = std::max(0, y - 1); j < std::min(height, y + 2); ++j) {
            if (grid[i][j] == 1) {
                neighbors += 1;
            }
        }
    }
    if (grid[x][y] == 1) {
        return (2 <= neighbors && neighbors <= 3) ? 1 : 0;
    } else {
        return (neighbors == 3) ? 1 : 0;
    }
}

std::vector<std::vector<int>> update_grid(std::vector<std::vector<int>>& grid, int width, int height) {
    std::vector<std::vector<int>> new_grid(width, std::vector<int>(height, 0));
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            new_grid[x][y] = update_cell(grid, x, y, width, height);
        }
    }
    return new_grid;
}

void main() {
    int width = 10;
    int height = 10;
    std::vector<std::vector<int>> grid(width, std::vector<int>(height, 0));
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            grid[x][y] = (x + y) % 2 ? 1 : 0;
        }
    }
    while (true) {
        grid = update_grid(grid, width, height);
    }
}