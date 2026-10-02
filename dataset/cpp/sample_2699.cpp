#include <vector>

class Automaton {
public:
    Automaton(int grid_size) {
        grid = std::vector<std::vector<int>>(grid_size, std::vector<int>(grid_size, 0));
        size = grid_size;
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = count_neighbors(i, j);
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
    std::vector<std::vector<int>> grid;
    int size;
};

void simulate(Automaton& automaton, int steps) {
    for (int _ = 0; _ < steps; ++_) {
        automaton.update();
    }
}

int main() {
    int grid_size = 10;
    int steps = 50;
    Automaton automaton(grid_size);
    simulate(automaton, steps);
    return 0;
}