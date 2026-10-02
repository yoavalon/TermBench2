public class sample_1983 {
    public static double[][] update_grid(double[][] grid) {
        double[][] new_grid = new double[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (i > 0 && j > 0 && (i < grid.length - 1) && (j < grid[0].length - 1)) {
                    new_grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
                } else {
                    new_grid[i][j] = grid[i][j];
                }
            }
        }
        return new_grid;
    }

    public static double[][] simulate(int n, int size) {
        double[][] grid = new double[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = (i == size / 2 && j == size / 2) ? 1.0 : 0.0;
            }
        }
        for (int _ = 0; _ < n; _++) {
            grid = update_grid(grid);
        }
        return grid;
    }

    public static void main(String[] args) {
        double[][] result = simulate(10, 5);
        for (double[] row : result) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}