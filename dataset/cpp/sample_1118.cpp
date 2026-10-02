#include <iostream>
#include <vector>

class Grid {
public:
    int size;
    std::vector<std::vector<int>> grid;

    Grid(int size) : size(size), grid(size, std::vector<int>(size, 0)) {}

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int neighbors = count_neighbors(i, j);
                if (grid[i][j] == 0) {
                    new_grid[i][j] = (neighbors == 3) ? 1 : 0;
                } else {
                    new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
                }
            }
        }
        grid = new_grid;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                int ni = x + i, nj = y + j;
                if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                    count += grid[ni][nj];
                }
            }
        }
        return count;
    }
};

void display(Grid& grid) {
    for (const auto& row : grid.grid) {
        for (int cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int size = 10;
    Grid grid(size);
    while (true) {
        display(grid);
        grid.update();
    }
    return 0;
}