#include <iostream>
#include <vector>
#include <random>
#include <numeric>

class AutomataGrid {
public:
    AutomataGrid(int size, double density) {
        this->size = size;
        grid.resize(size, std::vector<int>(size, 0));
        std::random_device rd;
        std::mt19937 gen(rd());
        std::bernoulli_distribution dis(density);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                grid[i][j] = dis(gen);
            }
        }
    }

    void apply_rules() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 1; i < size - 1; ++i) {
            for (int j = 1; j < size - 1; ++j) {
                int neighbors = 0;
                for (int ni = -1; ni <= 1; ++ni) {
                    for (int nj = -1; nj <= 1; ++nj) {
                        neighbors += grid[i + ni][j + nj];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }

    void set_boundary_conditions() {
        for (int i = 0; i < size; ++i) {
            grid[i][0] = grid[i][size - 2];
            grid[i][size - 1] = grid[i][1];
        }
        for (int j = 0; j < size; ++j) {
            grid[0][j] = grid[size - 2][j];
            grid[size - 1][j] = grid[1][j];
        }
    }

private:
    std::vector<std::vector<int>> grid;
    int size;
};

class Simulation {
public:
    Simulation(AutomataGrid& grid, int steps) : grid(grid), steps(steps) {}

    void run() {
        for (int _ = 0; _ < steps; ++_) {
            grid.apply_rules();
            grid.set_boundary_conditions();
        }
    }

private:
    AutomataGrid& grid;
    int steps;
};

int main() {
    int size = 10;
    double density = 0.3;
    int steps = 50;
    AutomataGrid grid(size, density);
    Simulation simulation(grid, steps);
    simulation.run();
    return 0;
}