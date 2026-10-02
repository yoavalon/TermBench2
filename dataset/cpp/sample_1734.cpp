#include <iostream>
#include <vector>

class CellularAutomaton {
public:
    CellularAutomaton(int size) : size(size) {
        grid = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = _count_neighbors(i, j);
                if (grid[i][j] == 0) {
                    if (neighbors == 3) {
                        new_grid[i][j] = 1;
                    }
                } else if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }

private:
    int _count_neighbors(int x, int y) {
        int count = 0;
        for (int i = std::max(0, x - 1); i < std::min(x + 2, size); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(y + 2, size); ++j) {
                if ((i, j) != (x, y)) {
                    count += grid[i][j];
                }
            }
        }
        return count;
    }

    std::vector<std::vector<int>> grid;
    int size;
};

void display(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << (cell ? '█' : ' ');
        }
        std::cout << std::endl;
    }
}

int main() {
    int size = 10;
    CellularAutomaton automaton(size);
    while (true) {
        display(automaton.grid);
        automaton.update();
    }
    return 0;
}