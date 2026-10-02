import java.util.Arrays;

public class sample_2204 {
    public static double[][] update_grid(double[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        double[][] new_grid = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                double total = 0.0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                            total += grid[ni][nj];
                        }
                    }
                }
                new_grid[i][j] = total / 9.0;
            }
        }
        return new_grid;
    }

    public static void simulate() {
        double[][] grid = new double[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                grid[i][j] = i + j;
            }
        }
        while (true) {
            grid = update_grid(grid);
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}