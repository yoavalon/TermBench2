#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_state(const std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size()));
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[y].size(); ++x) {
            int count = 0;
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dy == 0 && dx == 0) continue;
                    int ny = y + dy, nx = x + dx;
                    if (ny >= 0 && ny < grid.size() && nx >= 0 && nx < grid[y].size()) {
                        count += grid[ny][nx];
                    }
                }
            }
            if (grid[y][x] == 1 && count < 2) {
                new_grid[y][x] = 0;
            } else if (grid[y][x] == 1 && (count == 2 || count == 3)) {
                new_grid[y][x] = 1;
            } else if (grid[y][x] == 1 && count > 3) {
                new_grid[y][x] = 0;
            } else if (grid[y][x] == 0 && count == 3) {
                new_grid[y][x] = 1;
            }
        }
    }
    return new_grid;
}

void display_grid(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << (cell ? 'O' : ' ');
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void simulate(const std::vector<std::vector<int>>& grid) {
    display_grid(grid);
    simulate(update_state(grid));
}

int main() {
    std::vector<std::vector<int>> initial_grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    simulate(initial_grid);
    return 0;
}