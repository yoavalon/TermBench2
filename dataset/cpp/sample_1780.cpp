#include <iostream>
#include <vector>

class CellularAutomata {
public:
    CellularAutomata(int size) {
        grid.resize(size, std::vector<int>(size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(grid.size(), std::vector<int>(grid.size(), 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
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
        for (int i = std::max(0, x - 1); i < std::min((int)grid.size(), x + 2); ++i) {
            for (int j = std::max(0, y - 1); j < std::min((int)grid.size(), y + 2); ++j) {
                if ((i, j) != (x, y) && grid[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;
    }

private:
    std::vector<std::vector<int>> grid;
};

int main() {
    int size = 10;
    CellularAutomata ca(size);
    ca.grid[1][1] = 1;
    ca.grid[2][2] = 1;
    ca.grid[2][3] = 1;
    ca.grid[3][1] = 1;
    ca.grid[3][2] = 1;
    while (true) {
        ca.update();
        for (const auto& row : ca.grid) {
            for (int cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}