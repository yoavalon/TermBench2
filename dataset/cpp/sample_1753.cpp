#include <vector>

class Automaton {
public:
    Automaton(int size) : size(size), grid(size, std::vector<int>(size, 0)) {}

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
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
        for (int i = std::max(0, x - 1); i < std::min(size, x + 2); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(size, y + 2); ++j) {
                if ((i, j) != (x, y) && grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;
    }

private:
    int size;
    std::vector<std::vector<int>> grid;
};

class Simulator {
public:
    Simulator(Automaton& automaton) : automaton(automaton) {}

    void run() {
        while (true) {
            automaton.update();
        }
    }

private:
    Automaton& automaton;
};

void main() {
    int size = 10;
    Automaton automaton(size);
    Simulator simulator(automaton);
    simulator.run();
}