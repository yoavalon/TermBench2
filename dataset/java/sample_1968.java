import java.util.Arrays;

public class sample_1968 {
    public static double[][] updateGrid(double[][] grid) {
        double[][] newGrid = new double[grid.length][grid[0].length];
        for (int i = 1; i < grid.length - 1; i++) {
            for (int j = 1; j < grid[0].length - 1; j++) {
                double avg = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
                newGrid[i][j] = (grid[i][j] + avg) / 2.0;
            }
        }
        return newGrid;
    }

    public static double[][] simulate(double[][] grid, int steps) {
        for (int _ = 0; _ < steps; _++) {
            grid = updateGrid(grid);
        }
        return grid;
    }

    public static void main(String[] args) {
        int gridSize = 10;
        int steps = 5;
        double[][] grid = new double[gridSize][gridSize];
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                grid[i][j] = (i == gridSize / 2 && j == gridSize / 2) ? 1.0 : 0.0;
            }
        }
        double[][] result = simulate(grid, steps);
        for (double[] row : result) {
            for (double x : row) {
                System.out.printf("%.2f ", x);
            }
            System.out.println();
        }
    }
}