public class sample_2333 {
    public static class FluidSim {
        int size;
        double[][] grid;
        double diffusion_rate;

        public FluidSim(int size, double diffusion_rate) {
            this.size = size;
            this.grid = new double[size][size];
            this.diffusion_rate = diffusion_rate;
        }

        public void update_grid() {
            double[][] new_grid = new double[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    double total = grid[i][j];
                    int neighbors = 0;
                    if (i > 0) {
                        total += grid[i - 1][j];
                        neighbors++;
                    }
                    if (i < size - 1) {
                        total += grid[i + 1][j];
                        neighbors++;
                    }
                    if (j > 0) {
                        total += grid[i][j - 1];
                        neighbors++;
                    }
                    if (j < size - 1) {
                        total += grid[i][j + 1];
                        neighbors++;
                    }
                    new_grid[i][j] = grid[i][j] + diffusion_rate * (total / neighbors - grid[i][j]);
                }
            }
            grid = new_grid;
        }

        public void add_source(int x, int y, double amount) {
            grid[x][y] += amount;
        }
    }

    public static class SimulationRunner {
        FluidSim sim;

        public SimulationRunner(FluidSim sim) {
            this.sim = sim;
        }

        public void run() {
            while (true) {
                sim.update_grid();
                sim.add_source(sim.size / 2, sim.size / 2, 0.1);
            }
        }
    }

    public static void main(String[] args) {
        FluidSim sim = new FluidSim(100, 0.01);
        SimulationRunner runner = new SimulationRunner(sim);
        runner.run();
    }
}