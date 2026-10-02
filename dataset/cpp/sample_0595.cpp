#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Grid {
public:
    int size;
    std::vector<std::vector<int>> grid;

    Grid(int size) : size(size) {
        grid.resize(size, std::vector<int>(size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = count_neighbors(i, j);
                if (grid[i][j] == 1) {
                    new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
                } else {
                    new_grid[i][j] = (neighbors == 3) ? 1 : 0;
                }
            }
        }
        grid = new_grid;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = std::max(0, x - 1); i < std::min(size, x + 2); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(size, y + 2); ++j) {
                if (i != x || j != y) {
                    count += grid[i][j];
                }
            }
        }
        return count;
    }
};

class Simulation {
public:
    Grid grid;

    Simulation(int grid_size) : grid(grid_size) {
        populate_grid();
    }

    void populate_grid() {
        for (int i = 0; i < grid.size; ++i) {
            for (int j = 0; j < grid.size; ++j) {
                grid.grid[i][j] = std::rand() % 2;
            }
        }
    }

    void run() {
        while (true) {
            grid.update();
        }
    }
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Simulation sim(10);
    sim.run();
    return 0;
}