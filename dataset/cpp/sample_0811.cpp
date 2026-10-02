#include <iostream>
#include <vector>

class FluidSimulator {
public:
    FluidSimulator(int grid_size, int steps) {
        grid = std::vector<std::vector<int>>(grid_size, std::vector<int>(grid_size, 0));
        this->steps = steps;
        step_count = 0;
    }

    void update() {
        std::vector<std::vector<int>> new_grid = std::vector<std::vector<int>>(grid.size(), std::vector<int>(grid.size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int neighbors = count_neighbors(i, j);
                if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = grid[i][j];
                }
            }
        }
        grid = new_grid;
        step_count++;
    }

    int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if ((i != x || j != y) && i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size()) {
                    count += grid[i][j];
                }
            }
        }
        return count;
    }

    void run() {
        if (step_count < steps) {
            update();
            run();
        }
    }

private:
    std::vector<std::vector<int>> grid;
    int steps;
    int step_count;
};

void main() {
    FluidSimulator sim(10, 100);
    sim.run();
    for (const auto& row : sim.grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}