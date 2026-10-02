#include <iostream>
#include <vector>
#include <unordered_set>

class CellularAutomaton {
public:
    CellularAutomaton(int grid_size, const std::unordered_map<std::string, std::unordered_set<int>>& rule)
        : grid_size(grid_size), rule(rule) {
        grid = std::vector<std::vector<int>>(grid_size, std::vector<int>(grid_size, 0));
        grid[grid_size / 2][grid_size / 2] = 1;
    }

    void update() {
        std::vector<std::vector<int>> new_grid(grid_size, std::vector<int>(grid_size, 0));
        for (int i = 0; i < grid_size; ++i) {
            for (int j = 0; j < grid_size; ++j) {
                int neighbors = count_neighbors(i, j);
                new_grid[i][j] = apply_rule(grid[i][j], neighbors);
            }
        }
        grid = new_grid;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                if (i >= 0 && i < grid_size && j >= 0 && j < grid_size && !(i == x && j == y)) {
                    count += grid[i][j];
                }
            }
        }
        return count;
    }

    int apply_rule(int cell, int neighbors) {
        if (cell == 1 && rule.at("survive").find(neighbors) != rule.at("survive").end()) {
            return 1;
        } else if (cell == 0 && rule.at("birth").find(neighbors) != rule.at("birth").end()) {
            return 1;
        }
        return 0;
    }

private:
    int grid_size;
    std::unordered_map<std::string, std::unordered_set<int>> rule;
    std::vector<std::vector<int>> grid;
};

void main() {
    int size = 50;
    std::unordered_map<std::string, std::unordered_set<int>> rule = {
        {"survive", {2, 3}},
        {"birth", {3}}
    };
    CellularAutomaton ca(size, rule);
    for (int _ = 0; _ < 100; ++_) {
        ca.update();
    }
    for (const auto& row : ca.grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}