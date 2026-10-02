#include <vector>
#include <iostream>

class Grid {
public:
    Grid(int size) : size(size) {
        grid = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = get_neighbors(i, j);
                if (grid[i][j] == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                } else if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = grid[i][j];
                }
            }
        }
        grid = new_grid;
    }

    int get_neighbors(int x, int y) {
        int count = 0;
        for (int i = std::max(0, x - 1); i < std::min(size, x + 2); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(size, y + 2); ++j) {
                if ((i != x || j != y) && grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;
    }

private:
    std::vector<std::vector<int>> grid;
    int size;
};

class Simulation {
public:
    Simulation(Grid grid) : grid(grid) {}

    void run() {
        while (true) {
            grid.update();
        }
    }

private:
    Grid grid;
};

int main() {
    int size = 50;
    Grid grid(size);
    Simulation simulation(grid);
    simulation.run();
    return 0;
}