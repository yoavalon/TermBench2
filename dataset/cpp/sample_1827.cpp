#include <vector>
#include <iostream>

std::vector<std::vector<double>> simulate(int n) {
    std::vector<std::vector<double>> grid(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                grid[i][j] = 1.0;
            } else {
                grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            }
        }
    }
    return grid;
}

int main() {
    std::vector<std::vector<double>> result = simulate(10);
    return 0;
}