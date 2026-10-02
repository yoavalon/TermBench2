#include <iostream>
#include <vector>

class AutomataGrid {
public:
    AutomataGrid(int size) {
        grid = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid.size(), 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                int neighbors = count_neighbors(i, j);
                if (grid[i][j] == 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_grid[i][j] = 0;
                    } else {
                        new_grid[i][j] = 1;
                    }
                } else if (neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = std::max(0, x - 1); i < std::min(static_cast<int>(grid.size()), x + 2); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(static_cast<int>(grid[i].size()), y + 2); ++j) {
                if ((i, j) != (x, y) && grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;
    }

private:
    std::vector<std::vector<int>> grid;
};

void boundary_conditions(AutomataGrid& grid, int step_limit) {
    int steps = 0;
    while (steps < step_limit) {
        grid.update();
        steps += 1;
    }
}

int main() {
    int size = 10;
    int step_limit = 100;
    AutomataGrid automata(size);
    boundary_conditions(automata, step_limit);
    return 0;
}