#include <iostream>
#include <vector>
#include <numeric>

class Grid {
public:
    Grid(int size) : size(size), grid(size, std::vector<int>(size, 0)) {}

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 1; i < size - 1; ++i) {
            for (int j = 1; j < size - 1; ++j) {
                std::vector<int> neighbors;
                for (int ni = i - 1; ni <= i + 1; ++ni) {
                    for (int nj = j - 1; nj <= j + 1; ++nj) {
                        neighbors.push_back(grid[ni][nj]);
                    }
                }
                new_grid[i][j] = rules(neighbors);
            }
        }
        grid = new_grid;
    }

    int rules(const std::vector<int>& neighbors) {
        int count = std::accumulate(neighbors.begin(), neighbors.end(), 0) - grid[1][1];
        if (grid[1][1] == 1 && (count < 2 || count > 3)) {
            return 0;
        } else if (grid[1][1] == 0 && count == 3) {
            return 1;
        }
        return grid[1][1];
    }

private:
    int size;
    std::vector<std::vector<int>> grid;
};

class BoundaryHandler {
public:
    void apply(Grid& grid) {
        for (int i = 0; i < grid.size; ++i) {
            grid.grid[0][i] = grid.grid[grid.size - 2][i];
            grid.grid[grid.size - 1][i] = grid.grid[1][i];
        }
        for (int i = 0; i < grid.size; ++i) {
            grid.grid[i][0] = grid.grid[i][grid.size - 2];
            grid.grid[i][grid.size - 1] = grid.grid[i][1];
        }
    }
};

class Simulator {
public:
    Simulator(Grid& grid, BoundaryHandler& boundary_handler, int iterations)
        : grid(grid), boundary_handler(boundary_handler), iterations(iterations) {}

    void run() {
        for (int i = 0; i < iterations; ++i) {
            grid.update();
            boundary_handler.apply(grid);
        }
    }

private:
    Grid& grid;
    BoundaryHandler& boundary_handler;
    int iterations;
};

void main() {
    int size = 10;
    int iterations = 50;
    Grid grid(size);
    BoundaryHandler boundary_handler;
    Simulator simulator(grid, boundary_handler, iterations);
    simulator.run();
    for (const auto& row : grid.grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}