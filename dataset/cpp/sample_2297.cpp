#include <vector>

std::vector<std::vector<double>> init_grid(int size) {
    return std::vector<std::vector<double>>(size, std::vector<double>(size, 0.0));
}

std::vector<std::vector<double>> update_grid(const std::vector<std::vector<double>>& grid, double diffusion_rate) {
    int size = grid.size();
    std::vector<std::vector<double>> new_grid = init_grid(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double neighbors = 0.0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) {
                        continue;
                    }
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = grid[i][j] + diffusion_rate * neighbors;
        }
    }
    return new_grid;
}

int main() {
    int size = 100;
    double diffusion_rate = 0.01;
    std::vector<std::vector<double>> grid = init_grid(size);
    while (true) {
        grid = update_grid(grid, diffusion_rate);
    }
    return 0;
}