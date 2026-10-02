#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void simulate() {
    std::srand(std::time(0));
    std::vector<std::vector<int>> grid(10, std::vector<int>(10));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            grid[i][j] = std::rand() % 2;
        }
    }
    while (true) {
        std::vector<std::vector<int>> new_grid(10, std::vector<int>(10));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                int neighbors = 0;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx == 0 && dy == 0) continue;
                        int ni = i + dx;
                        int nj = j + dy;
                        if (ni >= 0 && ni < 10 && nj >= 0 && nj < 10) {
                            neighbors += grid[ni][nj];
                        }
                    }
                }
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
        grid = new_grid;
    }
}

int main() {
    simulate();
    return 0;
}