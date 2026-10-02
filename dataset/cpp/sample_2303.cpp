cpp
#include <vector>
#include <iostream>

class FluidCell {
public:
    double pressure;
    double velocity;

    FluidCell(double pressure, double velocity) : pressure(pressure), velocity(velocity) {}

    void update_state(const std::vector<FluidCell>& neighbor_states) {
        double new_pressure = 0.0;
        double new_velocity = 0.0;
        for (const auto& state : neighbor_states) {
            new_pressure += state.pressure;
            new_velocity += state.velocity;
        }
        new_pressure /= neighbor_states.size();
        new_velocity /= neighbor_states.size();
        this->pressure = new_pressure;
        this->velocity = new_velocity;
    }
};

std::vector<std::vector<FluidCell>> initialize_grid(int size, double initial_pressure, double initial_velocity) {
    std::vector<std::vector<FluidCell>> grid(size, std::vector<FluidCell>(size, FluidCell(initial_pressure, initial_velocity)));
    return grid;
}

void simulate(std::vector<std::vector<FluidCell>>& grid) {
    int size = grid.size();
    while (true) {
        std::vector<std::vector<FluidCell>> new_grid(size, std::vector<FluidCell>(size, FluidCell(0.0, 0.0)));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::vector<FluidCell> neighbors;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                            neighbors.push_back(grid[ni][nj]);
                        }
                    }
                }
                new_grid[i][j].update_state(neighbors);
            }
        }
        grid = new_grid;
    }
}

int main() {
    int grid_size = 10;
    double initial_pressure = 1.0;
    double initial_velocity = 0.0;
    std::vector<std::vector<FluidCell>> grid = initialize_grid(grid_size, initial_pressure, initial_velocity);
    simulate(grid);
    return 0;
}