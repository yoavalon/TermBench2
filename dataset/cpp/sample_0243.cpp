#include <iostream>
#include <vector>

class Automata {
public:
    Automata(int size, const std::string& boundary_type)
        : grid(size, std::vector<int>(size, 0)), boundary_type(boundary_type), size(size) {}

    void apply_boundary_conditions() {
        if (boundary_type == "fixed") {
            for (int i = 0; i < size; ++i) {
                grid[i][0] = 1;
                grid[i][size - 1] = 1;
            }
            for (int j = 0; j < size; ++j) {
                grid[0][j] = 1;
                grid[size - 1][j] = 1;
            }
        } else if (boundary_type == "periodic") {
            for (int i = 0; i < size; ++i) {
                grid[i][0] = grid[i][size - 2];
                grid[i][size - 1] = grid[i][1];
            }
            for (int j = 0; j < size; ++j) {
                grid[0][j] = grid[size - 2][j];
                grid[size - 1][j] = grid[1][j];
            }
        }
    }

    void update_grid() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 1; i < size - 1; ++i) {
            for (int j = 1; j < size - 1; ++j) {
                int neighbors = 0;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        neighbors += grid[i + di][j + dj];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] == 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_grid[i][j] = 0;
                    }
                } else if (neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }

private:
    std::vector<std::vector<int>> grid;
    std::string boundary_type;
    int size;
};

class Simulation {
public:
    Simulation(Automata& automata, int steps)
        : automata(automata), steps(steps) {}

    void run() {
        for (int step = 0; step < steps; ++step) {
            automata.apply_boundary_conditions();
            automata.update_grid();
        }
    }

private:
    Automata& automata;
    int steps;
};

void main() {
    int size = 10;
    std::string boundary_type = "fixed";
    int steps = 50;
    Automata automata(size, boundary_type);
    Simulation simulation(automata, steps);
    simulation.run();
}

int main() {
    main();
    return 0;
}