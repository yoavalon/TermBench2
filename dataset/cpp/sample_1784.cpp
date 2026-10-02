#include <iostream>
#include <vector>

class Automaton {
public:
    Automaton(int size) : size(size) {
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
        for (int i = std::max(0, x - 1); i < std::min(size, x + 2); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(size, y + 2); ++j) {
                if ((i, j) != (x, y) && grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;

    private:
        std::vector<std::vector<int>> grid;
        int size;
};

std::vector<std::vector<int>> run_simulation(int size, int steps) {
    Automaton automaton(size);
    for (int _ = 0; _ < steps; ++_) {
        automaton.update();
    }
    return automaton.grid;
}

int main() {
    int size = 50;
    int steps = 1000;
    std::vector<std::vector<int>> result = run_simulation(size, steps);
    for (const auto& row : result) {
        for (int cell : row) {
            std::cout << (cell ? '#' : '.');
        }
        std::cout << std::endl;
    }
    return 0;
}