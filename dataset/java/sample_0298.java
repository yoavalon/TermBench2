import java.util.Random;

public class sample_0298 {
    static class AutomataGrid {
        int[][] grid;
        int size;

        public AutomataGrid(int size, double density) {
            this.size = size;
            this.grid = new int[size][size];
            Random rand = new Random();
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    this.grid[i][j] = rand.nextDouble() < density ? 1 : 0;
                }
            }
        }

        public void apply_rules() {
            int[][] new_grid = new int[size][size];
            for (int i = 1; i < size - 1; i++) {
                for (int j = 1; j < size - 1; j++) {
                    int neighbors = 0;
                    for (int ni = -1; ni <= 1; ni++) {
                        for (int nj = -1; nj <= 1; nj++) {
                            neighbors += grid[i + ni][j + nj];
                        }
                    }
                    neighbors -= grid[i][j];
                    if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                        new_grid[i][j] = 0;
                    } else if (grid[i][j] == 0 && neighbors == 3) {
                        new_grid[i][j] = 1;
                    }
                }
            }
            this.grid = new_grid;
        }

        public void set_boundary_conditions() {
            for (int i = 0; i < size; i++) {
                grid[i][0] = grid[i][size - 2];
                grid[i][size - 1] = grid[i][1];
            }
            for (int j = 0; j < size; j++) {
                grid[0][j] = grid[size - 2][j];
                grid[size - 1][j] = grid[1][j];
            }
        }
    }

    static class Simulation {
        AutomataGrid grid;
        int steps;

        public Simulation(AutomataGrid grid, int steps) {
            this.grid = grid;
            this.steps = steps;
        }

        public void run() {
            for (int step = 0; step < steps; step++) {
                grid.apply_rules();
                grid.set_boundary_conditions();
            }
        }
    }

    public static void main(String[] args) {
        int size = 10;
        double density = 0.3;
        int steps = 50;
        AutomataGrid grid = new AutomataGrid(size, density);
        Simulation simulation = new Simulation(grid, steps);
        simulation.run();
    }
}