#include <iostream>
#include <vector>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            std::vector<int> neighbors;
            for (int di = -1; di < 2; ++di) {
                for (int dj = -1; dj < 2; ++dj) {
                    if (0 <= i + di && i + di < grid.size() && 0 <= j + dj && j + dj < grid[0].size()) {
                        neighbors.push_back(grid[i + di][j + dj]);
                    }
                }
            }
            int sum = 0;
            for (int neighbor : neighbors) {
                sum += neighbor;
            }
            new_grid[i][j] = sum / neighbors.size();
        }
    }
    return new_grid;
}

void display(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void simulate(const std::vector<std::vector<int>>& grid) {
    display(grid);
    simulate(update_grid(grid));
}

int main() {
    std::vector<std::vector<int>> grid = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    simulate(grid);
    return 0;
}