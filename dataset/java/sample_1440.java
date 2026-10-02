public class sample_1440 {

    static class Grid {
        int[][] grid;
        int size;

        Grid(int size) {
            this.grid = new int[size][size];
            this.size = size;
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = count_neighbors(i, j);
                    if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                        new_grid[i][j] = 0;
                    } else if (grid[i][j] == 0 && neighbors == 3) {
                        new_grid[i][j] = 1;
                    } else {
                        new_grid[i][j] = grid[i][j];
                    }
                }
            }
            grid = new_grid;
        }

        int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = x - 1; i <= x + 1; i++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    if ((i != x || j != y) && i >= 0 && i < size && j >= 0 && j < size) {
                        count += grid[i][j];
                    }
                }
            }
            return count;
        }
    }

    static class Simulation {
        Grid grid;
        int steps;

        Simulation(Grid grid) {
            this.grid = grid;
            this.steps = 0;
        }

        void run(int max_steps) {
            while (steps < max_steps) {
                grid.update();
                steps++;
            }
        }
    }

    public static void main(String[] args) {
        int size = 50;
        int max_steps = 100;
        Grid grid = new Grid(size);
        Simulation simulation = new Simulation(grid);
        simulation.run(max_steps);
    }
}