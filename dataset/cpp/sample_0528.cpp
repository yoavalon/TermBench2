#include <iostream>
#include <vector>

class Automaton {
public:
    Automaton(int size) : size(size), grid(size, std::vector<int>(size, 0)) {}

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = grid[(i - 1 + size) % size][(j - 1 + size) % size] + grid[(i - 1 + size) % size][j] + grid[(i - 1 + size) % size][(j + 1) % size] + grid[i][(j - 1 + size) % size] + grid[i][(j + 1) % size] + grid[(i + 1) % size][(j - 1 + size) % size] + grid[(i + 1) % size][j] + grid[(i + 1) % size][(j + 1) % size];
                if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }

private:
    int size;
    std::vector<std::vector<int>> grid;
};

class BoundaryHandler {
public:
    BoundaryHandler(Automaton& automaton) : automaton(automaton) {}

    void apply_boundary_conditions() {
        for (int j = 0; j < automaton.size; ++j) {
            automaton.grid[0][j] = 0;
            automaton.grid[automaton.size - 1][j] = 0;
        }
        for (int i = 0; i < automaton.size; ++i) {
            automaton.grid[i][0] = 0;
            automaton.grid[i][automaton.size - 1] = 0;
        }
    }

private:
    Automaton& automaton;
};

int main() {
    int size = 100;
    Automaton automaton(size);
    BoundaryHandler boundary_handler(automaton);
    automaton.grid[1][2] = 1;
    automaton.grid[2][3] = 1;
    automaton.grid[3][1] = 1;
    automaton.grid[3][2] = 1;
    automaton.grid[3][3] = 1;
    while (true) {
        boundary_handler.apply_boundary_conditions();
        automaton.update();
    }
    return 0;
}