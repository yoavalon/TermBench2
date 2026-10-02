public class sample_0529 {

    static class Grid {
        int[][] grid;

        Grid(int size) {
            grid = new int[size][size];
        }

        void update() {
            int[][] new_grid = new int[grid.length][grid[0].length];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    int neighbors = count_neighbors(i, j);
                    if (grid[i][j] == 1) {
                        if (neighbors < 2 || neighbors > 3) {
                            new_grid[i][j] = 0;
                        } else {
                            new_grid[i][j] = 1;
                        }
                    } else if (neighbors == 3) {
                        new_grid[i][j] = 1;
                    }
                }
            }
            grid = new_grid;
        }

        int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = x - 1; i < x + 2; i++) {
                for (int j = y - 1; j < y + 2; j++) {
                    if ((i != x || j != y) && 0 <= i && i < grid.length && 0 <= j && j < grid[i].length) {
                        count += grid[i][j];
                    }
                }
            }
            return count;
        }
    }

    static class Simulation {
        Grid grid;

        Simulation(int grid_size) {
            grid = new Grid(grid_size);
        }

        void run() {
            while (true) {
                grid.update();
            }
        }
    }

    public static void main(String[] args) {
        Simulation simulation = new Simulation(10);
        simulation.run();
    }
}