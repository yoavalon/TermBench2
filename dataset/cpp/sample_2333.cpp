#include <vector>

class FluidSim {
public:
    FluidSim(int size, double diffusion_rate) : size(size), diffusion_rate(diffusion_rate) {
        grid.resize(size, std::vector<double>(size, 0.0));
    }

    void update_grid() {
        std::vector<std::vector<double>> new_grid(size, std::vector<double>(size, 0.0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                double total = grid[i][j];
                int neighbors = 0;
                if (i > 0) {
                    total += grid[i - 1][j];
                    neighbors += 1;
                }
                if (i < size - 1) {
                    total += grid[i + 1][j];
                    neighbors += 1;
                }
                if (j > 0) {
                    total += grid[i][j - 1];
                    neighbors += 1;
                }
                if (j < size - 1) {
                    total += grid[i][j + 1];
                    neighbors += 1;
                }
                new_grid[i][j] = grid[i][j] + diffusion_rate * (total / neighbors - grid[i][j]);
            }
        }
        grid = new_grid;
    }

    void add_source(int x, int y, double amount) {
        grid[x][y] += amount;
    }

private:
    int size;
    double diffusion_rate;
    std::vector<std::vector<double>> grid;
};

class SimulationRunner {
public:
    SimulationRunner(FluidSim& sim) : sim(sim) {}

    void run() {
        while (true) {
            sim.update_grid();
            sim.add_source(sim.size / 2, sim.size / 2, 0.1);
        }
    }

private:
    FluidSim& sim;
};

int main() {
    FluidSim sim(100, 0.01);
    SimulationRunner runner(sim);
    runner.run();
    return 0;
}