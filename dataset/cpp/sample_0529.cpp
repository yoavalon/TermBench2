#include <vector>
#include <iostream>

class Grid {
public:
    Grid(int size) : grid(size, std::vector<int>(size, 0)) {}

    void update() {
        std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid[0].size(), 0));
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
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                if ((i != x || j != y) && i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size()) {
                    count += grid[i][j];
                }
            }
        }
        return count;
    }

private:
    std::vector<std::vector<int>> grid;
};

class Simulation {
public:
    Simulation(int grid_size) : grid(grid_size) {}

    void run() {
        while (true) {
            grid.update();
        }
    }

private:
    Grid grid;
};

int main() {
    Simulation simulation(10);
    simulation.run();
    return 0;
}