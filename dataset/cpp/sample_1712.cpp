#include <vector>
#include <iostream>

class CellularAutomata {
public:
    CellularAutomata(int size) : size(size) {
        grid.resize(size, std::vector<int>(size, 0));
    }

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
        for (int i = std::max(0, x - 1); i < std::min(x + 2, size); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(y + 2, size); ++j) {
                if ((i != x || j != y) && grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;

private:
    std::vector<std::vector<int>> grid;
    int size;
};

void main() {
    CellularAutomata ca(10);
    ca.grid[5][5] = 1;
    ca.grid[5][6] = 1;
    ca.grid[6][5] = 1;
    ca.grid[6][6] = 1;
    while (true) {
        ca.update();
    }
}