#include <iostream>
#include <vector>

class RuleSet {
public:
    int apply(const std::vector<std::vector<int>>& grid, int x, int y) {
        int neighbors = count_neighbors(grid, x, y);
        return neighbors == 2 ? 1 : 0;
    }

    int count_neighbors(const std::vector<std::vector<int>>& grid, int x, int y) {
        int count = 0;
        for (int i = std::max(0, x - 1); i < std::min((int)grid.size(), x + 2); ++i) {
            for (int j = std::max(0, y - 1); j < std::min((int)grid.size(), y + 2); ++j) {
                if ((i, j) != (x, y) && grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;
    }
};

class FluidSimulator {
public:
    FluidSimulator(int grid_size, const RuleSet& rules) : rules(rules) {
        grid.resize(grid_size, std::vector<int>(grid_size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid.size(), 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                new_grid[i][j] = rules.apply(grid, i, j);
            }
        }
        grid = new_grid;
    }

    void display() {
        for (const auto& row : grid) {
            for (int val : row) {
                std::cout << val << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

private:
    std::vector<std::vector<int>> grid;
    const RuleSet& rules;
};

void main() {
    int grid_size = 10;
    RuleSet rules;
    FluidSimulator simulator(grid_size, rules);
    simulator.grid[4][4] = 1;
    simulator.grid[5][4] = 1;
    simulator.grid[4][5] = 1;
    while (true) {
        simulator.display();
        simulator.update();
    }
}