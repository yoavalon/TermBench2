import java.util.Arrays;

public class sample_2299 {
    public static double[][] update_state(double[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        double[][] new_grid = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                double value = 0.0;
                for (int[] neighbor : new int[][]{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}}) {
                    int x = neighbor[0];
                    int y = neighbor[1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        value += grid[x][y];
                    }
                }
                new_grid[i][j] = value / 4.0;
            }
        }
        return new_grid;
    }

    public static void simulate(double[][] grid) {
        while (true) {
            grid = update_state(grid);
        }
    }

    public static void main(String[] args) {
        int grid_size = 10;
        double[][] initial_grid = new double[grid_size][grid_size];
        for (int i = 0; i < grid_size; i++) {
            for (int j = 0; j < grid_size; j++) {
                initial_grid[i][j] = i * j;
            }
        }
        simulate(initial_grid);
    }
}