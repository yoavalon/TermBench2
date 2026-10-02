#include <iostream>
#include <vector>
#include <random>
#include <matplotlib.pyplot>
#include <matplotlib/axes>
#include <matplotlib/figure>

std::vector<std::vector<int>> initialize_grid(int size) {
    std::vector<std::vector<int>> grid(size, std::vector<int>(size));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dis(0.5);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = dis(gen);
        }
    }
    return grid;
}

std::vector<std::vector<int>> update_grid(const std::vector<std::vector<int>>& grid) {
    int size = grid.size();
    std::vector<std::vector<int>> new_grid(size, std::vector<int>(size));
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            int neighbors = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di != 0 || dj != 0) {
                        neighbors += grid[i + di][j + dj];
                    }
                }
            }
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

void main() {
    int grid_size = 100;
    std::vector<std::vector<int>> grid = initialize_grid(grid_size);
    matplotlib::pyplot::ion();
    matplotlib::figure::figure fig;
    matplotlib::axes::axes ax = fig.add_subplot(111);
    matplotlib::pyplot::imshow(grid, "binary");
    while (true) {
        grid = update_grid(grid);
        ax.imshow(grid, "binary");
        matplotlib::pyplot::pause(0.1);
    }
}

int main() {
    main();
    return 0;
}