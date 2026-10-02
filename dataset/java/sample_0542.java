public class sample_0542 {

    static class Grid {
        int[][] grid;
        int size;

        Grid(int size) {
            this.size = size;
            this.grid = new int[size][size];
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = get_neighbors(i, j);
                    if (grid[i][j] == 0 && neighbors == 3) {
                        new_grid[i][j] = 1;
                    } else if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                        new_grid[i][j] = 0;
                    } else {
                        new_grid[i][j] = grid[i][j];
                    }
                }
            }
            grid = new_grid;
        }

        int get_neighbors(int x, int y) {
            int count = 0;
            for (int i = Math.max(0, x - 1); i < Math.min(size, x + 2); i++) {
                for (int j = Math.max(0, y - 1); j < Math.min(size, y + 2); j++) {
                    if ((i != x || j != y) && grid[i][j] == 1) {
                        count++;
                    }
                }
            }
            return count;
        }
    }

    static class Simulation {
        Grid grid;

        Simulation(Grid grid) {
            this.grid = grid;
        }

        void run() {
            while (true) {
                grid.update();
            }
        }
    }

    public static void main(String[] args) {
        int size = 50;
        Grid grid = new Grid(size);
        Simulation simulation = new Simulation(grid);
        simulation.run();
    }
}