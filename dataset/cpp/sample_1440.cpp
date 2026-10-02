#include <iostream>
#include <vector>

class Grid {
public:
    Grid(int size) : size(size) {
        grid.resize(size, std::vector<int>(size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = count_neighbors(i, j);
                if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = grid[i][j];
                }
            }
        }
        grid = new_grid;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                if ((i != x || j != y) && i >= 0 && i < size && j >= 0 && j < size) {
                    count += grid[i][j];
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
    Simulation(Grid& grid) : grid(grid), steps(0) {}

    void run(int max_steps) {
        while (steps < max_steps) {
            grid.update();
            ++steps;
        }
    }

private:
    Grid& grid;
    int steps;
};

void main() {
    int size = 50;
    int max_steps = 100;
    Grid grid(size);
    Simulation simulation(grid);
    simulation.run(max_steps);
}

int main() {
    main();
    return 0;
}