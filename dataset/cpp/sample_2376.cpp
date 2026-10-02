#include <iostream>
#include <vector>

class CellularAutomata {
public:
    CellularAutomata(int size, int rule) {
        grid = std::vector<std::vector<float>>(size, std::vector<float>(size, 0.0f));
        grid[size / 2][size / 2] = 1.0f;
        this->rule = rule;
    }

    float apply_rule(const std::vector<std::vector<float>>& neighborhood) {
        float s = 0.0f;
        for (int i = 0; i < neighborhood.size(); ++i) {
            for (int j = 0; j < neighborhood[i].size(); ++j) {
                s += neighborhood[i][j];
            }
        }
        if (s == 3) {
            return 1.0f;
        } else if (s == 2) {
            return grid[neighborhood.size() / 2][neighborhood[0].size() / 2];
        } else {
            return 0.0f;
        }
    }

    void update_grid() {
        std::vector<std::vector<float>> new_grid(grid.size(), std::vector<float>(grid[0].size(), 0.0f));
        for (int i = 1; i < grid.size() - 1; ++i) {
            for (int j = 1; j < grid[i].size() - 1; ++j) {
                std::vector<std::vector<float>> neighborhood(
                    grid.begin() + i - 1, grid.begin() + i + 2);
                for (auto& row : neighborhood) {
                    row.erase(row.begin(), row.begin() + j - 1);
                    row.erase(row.begin() + 2, row.end());
                }
                new_grid[i][j] = apply_rule(neighborhood);
            }
        }
        grid = new_grid;
    }

private:
    std::vector<std::vector<float>> grid;
    int rule;
};

class FluidSimulation {
public:
    FluidSimulation(int size, int rule) : ca(size, rule) {}

    void simulate() {
        while (true) {
            ca.update_grid();
        }
    }

private:
    CellularAutomata ca;
};

int main() {
    FluidSimulation sim(50, 30);
    sim.simulate();
    return 0;
}