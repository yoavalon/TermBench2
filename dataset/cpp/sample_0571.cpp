#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Grid {
public:
    int width, height;
    std::vector<std::vector<int>> grid;

    Grid(int width, int height) : width(width), height(height) {
        grid = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(height, std::vector<int>(width, 0));
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int neighbors = count_neighbors(x, y);
                if (grid[y][x] == 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_grid[y][x] = 0;
                    } else {
                        new_grid[y][x] = 1;
                    }
                } else if (neighbors == 3) {
                    new_grid[y][x] = 1;
                }
            }
        }
        grid = new_grid;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if (i == 0 && j == 0) continue;
                int nx = (x + i + width) % width;
                int ny = (y + j + height) % height;
                count += grid[ny][nx];
            }
        }
        return count;
    }

    void display() {
        for (const auto& row : grid) {
            for (int cell : row) {
                std::cout << (cell ? 'O' : ' ');
            }
            std::cout << std::endl;
        }
    }
};

class Simulation {
public:
    Grid grid;

    Simulation(Grid grid) : grid(grid) {}

    void run() {
        while (true) {
            grid.update();
            grid.display();
            for (int i = 0; i < grid.width; ++i) std::cout << "-";
            std::cout << std::endl;
        }
    }
};

int main() {
    int width = 20, height = 20;
    Grid grid(width, height);
    std::srand(std::time(0));
    for (int i = 0; i < 50; ++i) {
        int x = std::rand() % width;
        int y = std::rand() % height;
        grid.grid[y][x] = 1;
    }
    Simulation simulation(grid);
    simulation.run();
    return 0;
}