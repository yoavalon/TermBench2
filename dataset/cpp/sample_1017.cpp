#include <iostream>
#include <vector>
#include <random>

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
    for (int x = 0; x < size; ++x) {
        for (int y = 0; y < size; ++y) {
            int neighbors = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx != 0 || dy != 0) {
                        neighbors += grid[(x + dx + size) % size][(y + dy + size) % size];
                    }
                }
            }
            new_grid[x][y] = (2 <= neighbors && neighbors <= 3) ? 1 : 0;
        }
    }
    return new_grid;
}

void simulate(std::vector<std::vector<int>>& grid) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    if (grid.empty()) {
        grid.resize(10, std::vector<int>(10, 0));
        for (auto& row : grid) {
            for (auto& cell : row) {
                cell = dis(gen);
            }
        }
    }

    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << cell;
        }
        std::cout << '\n';
    }

    simulate(update_grid(grid));
}

int main() {
    std::vector<std::vector<int>> grid;
    simulate(grid);
    return 0;
}