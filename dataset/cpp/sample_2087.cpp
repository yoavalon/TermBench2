#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <cmath>

class FluidDynamics {
public:
    FluidDynamics(int size, double viscosity, double density) {
        grid = std::vector<std::vector<double>>(size, std::vector<double>(size));
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                grid[i][j] = dis(gen);
            }
        }
        this->viscosity = viscosity;
        this->density = density;
    }

    void update_velocity() {
        int size = grid.size();
        std::vector<std::vector<double>> padded_grid(size + 2, std::vector<double>(size + 2, 0.0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                padded_grid[i + 1][j + 1] = grid[i][j];
            }
        }

        std::vector<std::vector<double>> laplacian(size, std::vector<double>(size, 0.0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                laplacian[i][j] = padded_grid[i][j] + padded_grid[i][j + 1] + padded_grid[i][j + 2] +
                                  padded_grid[i + 1][j] + padded_grid[i + 1][j + 2] +
                                  padded_grid[i + 2][j] + padded_grid[i + 2][j + 1] + padded_grid[i + 2][j + 2];
                laplacian[i][j] -= 9 * grid[i][j];
            }
        }

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                grid[i][j] += viscosity * laplacian[i][j] / density;
            }
        }
    }

    void simulate(int steps) {
        for (int _ = 0; _ < steps; ++_) {
            update_velocity();
        }
    }

private:
    std::vector<std::vector<double>> grid;
    double viscosity;
    double density;
};

class SimulationController {
public:
    SimulationController(FluidDynamics& fluid_dynamics, bool (*termination_condition)(const FluidDynamics&)) {
        this->fluid_dynamics = fluid_dynamics;
        this->termination_condition = termination_condition;
    }

    void run() {
        for (int _ = 0; _ < 100; ++_) {
            fluid_dynamics.simulate(10);
            if (check_condition()) {
                break;
            }
        }
    }

    bool check_condition() {
        int size = fluid_dynamics.grid.size();
        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                sum += fluid_dynamics.grid[i][j];
            }
        }
        double mean = sum / (size * size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (std::abs(fluid_dynamics.grid[i][j] - mean) > 1e-6) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    FluidDynamics& fluid_dynamics;
    bool (*termination_condition)(const FluidDynamics&);
};

int main() {
    int size = 50;
    double viscosity = 0.01;
    double density = 1.0;
    FluidDynamics fluid_dynamics(size, viscosity, density);
    auto termination_condition = [](const FluidDynamics& fd) {
        return fd.check_condition();
    };
    SimulationController controller(fluid_dynamics, termination_condition);
    controller.run();
    return 0;
}