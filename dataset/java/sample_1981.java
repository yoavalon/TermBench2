public class sample_1981 {
    public static double[][] update_state(double[][] grid) {
        double[][] new_grid = new double[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) {
                            continue;
                        }
                        int ni = i + x;
                        int nj = j + y;
                        if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[0].length) {
                            neighbors += grid[ni][nj];
                        }
                    }
                }
                new_grid[i][j] = neighbors / 9.0;
            }
        }
        return new_grid;
    }

    public static double[][] run_simulation(int steps, int size) {
        double[][] grid = new double[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
        for (int _ = 0; _ < steps; _) {
            grid = update_state(grid);
        }
        return grid;
    }

    public static void main(String[] args) {
        double[][] result = run_simulation(10, 5);
        for (double[] row : result) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}