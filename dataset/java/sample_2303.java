public class sample_2303 {

    static class FluidCell {
        double pressure;
        double velocity;

        FluidCell(double pressure, double velocity) {
            this.pressure = pressure;
            this.velocity = velocity;
        }

        void update_state(FluidCell[] neighbors) {
            double new_pressure = 0;
            double new_velocity = 0;
            for (FluidCell state : neighbors) {
                new_pressure += state.pressure;
                new_velocity += state.velocity;
            }
            new_pressure /= neighbors.length;
            new_velocity /= neighbors.length;
            this.pressure = new_pressure;
            this.velocity = new_velocity;
        }
    }

    static FluidCell[][] initialize_grid(int size, double initial_pressure, double initial_velocity) {
        FluidCell[][] grid = new FluidCell[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = new FluidCell(initial_pressure, initial_velocity);
            }
        }
        return grid;
    }

    static void simulate(FluidCell[][] grid) {
        int size = grid.length;
        while (true) {
            FluidCell[][] new_grid = new FluidCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    new_grid[i][j] = new FluidCell(0, 0);
                    FluidCell[] neighbors = new FluidCell[8];
                    int index = 0;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            if (di == 0 && dj == 0) continue;
                            int ni = i + di;
                            int nj = j + dj;
                            if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                                neighbors[index++] = grid[ni][nj];
                            }
                        }
                    }
                    new_grid[i][j].update_state(neighbors);
                }
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        int grid_size = 10;
        double initial_pressure = 1.0;
        double initial_velocity = 0.0;
        FluidCell[][] grid = initialize_grid(grid_size, initial_pressure, initial_velocity);
        simulate(grid);
    }
}