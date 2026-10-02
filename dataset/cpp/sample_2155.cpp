#include <vector>

void simulate_flow(int n) {
    std::vector<std::vector<double>> grid(n, std::vector<double>(n, 0.0));
    while (true) {
        std::vector<std::vector<double>> new_grid(n, std::vector<double>(n, 0.0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                new_grid[i][j] = (grid[i][(j - 1 + n) % n] + grid[i][(j + 1) % n] + grid[(i - 1 + n) % n][j] + grid[(i + 1) % n][j]) / 4;
            }
        }
        grid = new_grid;
    }
}

int main() {
    simulate_flow(10);
    return 0;
}