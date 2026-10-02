#include <iostream>
#include <vector>

class CellularAutomata {
public:
    CellularAutomata(int size) : size(size) {
        grid.resize(size, std::vector<int>(size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = _count_neighbors(i, j);
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

private:
    int _count_neighbors(int x, int y) {
        int count = 0;
        for (int i = std::max(0, x - 1); i < std::min(x + 2, size); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(y + 2, size); ++j) {
                if ((i, j) != (x, y) && grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;
    }

    std::vector<std::vector<int>> grid;
    int size;
};

void main() {
    int size = 10;
    CellularAutomata ca(size);
    for (int _ = 0; _ < 100; ++_) {
        ca.update();
    }
    for (const auto& row : ca.grid) {
        for (int cell : row) {
            std::cout << (cell ? '*' : ' ');
        }
        std::cout << std::endl;
    }
}