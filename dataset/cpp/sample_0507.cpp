#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Grid {
public:
    int size;
    std::vector<std::vector<int>> grid;

    Grid(int size) : size(size) {
        grid.resize(size, std::vector<int>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                grid[i][j] = rand() % 2;
            }
        }
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int state = grid[i][j];
                int neighbors = count_neighbors(i, j);
                if (state == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = state;
                }
            }
        }
        grid = new_grid;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = std::max(0, x - 1); i < std::min(x + 2, size); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(y + 2, size); ++j) {
                if ((i, j) != (x, y)) {
                    count += grid[i][j];
                }
            }
        }
        return count;
};

class Simulation {
public:
    Grid grid;

    Simulation(Grid grid) : grid(grid) {}

    void run() {
        while (true) {
            grid.update();
            display();
        }
    }

    void display() {
        for (const auto& row : grid.grid) {
            for (int cell : row) {
                std::cout << (cell ? '#' : ' ');
            }
            std::cout << std::endl;
        }
        for (int i = 0; i < grid.size; ++i) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
};

int main() {
    srand(time(0));
    int size = 50;
    Grid grid(size);
    Simulation simulation(grid);
    simulation.run();
    return 0;
}