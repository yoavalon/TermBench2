#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void simulate() {
    std::vector<std::vector<int>> grid(10, std::vector<int>(10, 0));
    while (true) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                std::vector<int> neighbors;
                if (i > 0) neighbors.push_back(grid[i - 1][j]);
                if (i < 9) neighbors.push_back(grid[i + 1][j]);
                if (j > 0) neighbors.push_back(grid[i][j - 1]);
                if (j < 9) neighbors.push_back(grid[i][j + 1]);
                int sum_neighbors = 0;
                for (int n : neighbors) {
                    sum_neighbors += n;
                }
                if (sum_neighbors > 4) {
                    grid[i][j] = 1;
                } else {
                    grid[i][j] = std::rand() % 2;
                }
            }
        }
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    simulate();
    return 0;
}