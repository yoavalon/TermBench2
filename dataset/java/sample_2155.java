public class sample_2155 {
    public static void simulate_flow(int n) {
        double[][] grid = new double[n][n];
        while (true) {
            double[][] new_grid = new double[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    new_grid[i][j] = (grid[i][(j - 1 + n) % n] + grid[i][(j + 1) % n] + grid[(i - 1 + n) % n][j] + grid[(i + 1) % n][j]) / 4;
                }
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        simulate_flow(10);
    }
}