import java.util.Arrays;

public class sample_1827 {
    public static double[][] simulate(int n) {
        double[][] grid = new double[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                    grid[i][j] = 1.0;
                } else {
                    grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
                }
            }
        }
        return grid;
    }

    public static void main(String[] args) {
        double[][] result = simulate(10);
        for (double[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }
}