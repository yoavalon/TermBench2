import java.util.Arrays;

public class sample_0243 {

    static class Automata {
        int[][] grid;
        String boundary_type;
        int size;

        Automata(int size, String boundary_type) {
            this.grid = new int[size][size];
            this.boundary_type = boundary_type;
            this.size = size;
        }

        void apply_boundary_conditions() {
            if (boundary_type.equals("fixed")) {
                for (int i = 0; i < size; i++) {
                    grid[i][0] = 1;
                    grid[i][size - 1] = 1;
                }
                for (int j = 0; j < size; j++) {
                    grid[0][j] = 1;
                    grid[size - 1][j] = 1;
                }
            } else if (boundary_type.equals("periodic")) {
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

        void update_grid() {
            int[][] new_grid = new int[size][size];
            for (int i = 1; i < size - 1; i++) {
                for (int j = 1; j < size - 1; j++) {
                    int neighbors = 0;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            neighbors += grid[i + di][j + dj];
                        }
                    }
                    neighbors -= grid[i][j];
                    if (grid[i][j] == 1) {
                        if (neighbors < 2 || neighbors > 3) {
                            new_grid[i][j] = 0;
                        }
                    } else if (neighbors == 3) {
                        new_grid[i][j] = 1;
                    }
                }
            }
            grid = new_grid;
        }
    }

    static class Simulation {
        Automata automata;
        int steps;

        Simulation(Automata automata, int steps) {
            this.automata = automata;
            this.steps = steps;
        }

        void run() {
            for (int _ = 0; _ < steps; _++) {
                automata.apply_boundary_conditions();
                automata.update_grid();
            }
        }
    }

    public static void main(String[] args) {
        int size = 10;
        String boundary_type = "fixed";
        int steps = 50;
        Automata automata = new Automata(size, boundary_type);
        Simulation simulation = new Simulation(automata, steps);
        simulation.run();
    }
}