#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class CellularAutomaton {
public:
    CellularAutomaton(int size) {
        grid.resize(size, std::vector<int>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                grid[i][j] = std::rand() % 2;
            }
        }
    }

    void update() {
        new_grid = grid;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                int sum = 0;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        int ni = (i + di + grid.size()) % grid.size();
                        int nj = (j + dj + grid.size()) % grid.size();
                        sum += grid[ni][nj];
                    }
                }
                new_grid[i][j] = (sum == 3) || (grid[i][j] == 1 && sum == 2);
            }
        }
        grid = new_grid;
    }

    std::vector<std::vector<int>> get_state() {
        return grid;
    }

private:
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> new_grid;
};

class FluidSimulator {
public:
    FluidSimulator(int size, int steps) : size(size), steps(steps), ca(size) {}

    void simulate() {
        for (int _ = 0; _ < steps; ++_) {
            ca.update();
        }
    }

    std::vector<std::vector<int>> get_result() {
        return ca.get_state();
    }

private:
    int size;
    int steps;
    CellularAutomaton ca;
};

int main() {
    int size = 100;
    int steps = 1000;
    FluidSimulator simulator(size, steps);
    simulator.simulate();
    std::vector<std::vector<int>> result = simulator.get_result();
    for (const auto& row : result) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}