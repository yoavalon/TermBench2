#include <iostream>
#include <vector>

int simulate(int a, int b, int c, int d) {
    if (c > d) {
        return b;
    }
    return simulate(b, a, c + 1, d);
}

std::vector<std::vector<int>> fluid_dynamics(int n, int m) {
    std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = simulate(i, j, 0, n);
        }
    }
    return grid;
}

void print_grid(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    auto result = fluid_dynamics(5, 5);
    print_grid(result);
    return 0;
}