#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class CellAutomata {
public:
    CellAutomata(int grid_size) : grid_size(grid_size) {
        grid = initialize_grid();
    }

    std::vector<std::vector<int>> initialize_grid() {
        std::vector<std::vector<int>> new_grid(grid_size, std::vector<int>(grid_size));
        for (int i = 0; i < grid_size; ++i) {
            for (int j = 0; j < grid_size; ++j) {
                new_grid[i][j] = rand() % 2;
            }
        }
        return new_grid;
    }

    void update_grid() {
        std::vector<std::vector<int>> new_grid(grid_size, std::vector<int>(grid_size));
        for (int i = 0; i < grid_size; ++i) {
            for (int j = 0; j < grid_size; ++j) {
                int neighbors = count_neighbors(i, j);
                if (grid[i][j] == 1) {
                    if (neighbors == 2 || neighbors == 3) {
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
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int ni = (x + i + grid_size) % grid_size;
                int nj = (y + j + grid_size) % grid_size;
                count += grid[ni][nj];
            }
        }
        return count;
private:
    int grid_size;
    std::vector<std::vector<int>> grid;
};

void main() {
    int size = 50;
    CellAutomata automata(size);
    while (true) {
        automata.update_grid();
    }
}