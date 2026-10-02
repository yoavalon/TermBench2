#include <vector>
#include <iostream>

class FluidSimulator {
public:
    FluidSimulator(int grid_size) : size(grid_size) {
        grid = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
    }

    void update() {
        std::vector<std::vector<int>> new_grid(size, std::vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                new_grid[i][j] = apply_rules(i, j);
            }
        }
        grid = new_grid;
    }

    int apply_rules(int x, int y) {
        std::vector<int> neighbors = get_neighbors(x, y);
        int count = 0;
        for (int n : neighbors) {
            count += n;
        }
        if (grid[x][y] == 1) {
            return count > 1 ? 1 : 0;
        } else {
            return count == 3 ? 1 : 0;
        }
    }

    std::vector<int> get_neighbors(int x, int y) {
        std::vector<std::pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };
        std::vector<int> neighbors;
        for (auto [dx, dy] : directions) {
            int nx = (x + dx + size) % size;
            int ny = (y + dy + size) % size;
            neighbors.push_back(grid[nx][ny]);
        }
        return neighbors;
    }

private:
    std::vector<std::vector<int>> grid;
    int size;
};

class BoundaryConditionApplier {
public:
    BoundaryConditionApplier(FluidSimulator& simulator) : simulator(simulator) {}

    void apply() {
        for (int i = 0; i < simulator.size; ++i) {
            simulator.grid[i][0] = 1;
            simulator.grid[i][simulator.size - 1] = 1;
            simulator.grid[0][i] = 1;
            simulator.grid[simulator.size - 1][i] = 1;
        }
    }

private:
    FluidSimulator& simulator;
};

int main() {
    int grid_size = 10;
    FluidSimulator simulator(grid_size);
    BoundaryConditionApplier boundary_conditions(simulator);
    while (true) {
        boundary_conditions.apply();
        simulator.update();
    }
    return 0;
}