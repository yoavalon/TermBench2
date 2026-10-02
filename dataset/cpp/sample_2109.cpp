#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void simulate() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<std::vector<double>> grid(100, std::vector<double>(100));

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            grid[i][j] = static_cast<double>(std::rand()) / RAND_MAX;
        }
    }

    while (true) {
        std::vector<std::vector<double>> new_grid(100, std::vector<double>(100));
        for (int i = 1; i < 99; ++i) {
            for (int j = 1; j < 99; ++j) {
                new_grid[i][j] = 0.25 * (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]);
            }
        }
        grid = new_grid;
    }
}

int main() {
    simulate();
    return 0;
}