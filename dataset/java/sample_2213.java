import java.util.Random;

public class sample_2213 {
    public static double[][] initialize_grid(int size) {
        double[][] grid = new double[size][size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = rand.nextDouble();
            }
        }
        return grid;
    }

    public static double[][] evolve(double[][] grid, int steps) {
        for (int step = 0; step < steps; step++) {
            double[][] newGrid = new double[grid.length][grid[0].length];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[0].length; j++) {
                    int top = (i - 1 + grid.length) % grid.length;
                    int bottom = (i + 1) % grid.length;
                    int left = (j - 1 + grid[0].length) % grid[0].length;
                    int right = (j + 1) % grid[0].length;
                    newGrid[i][j] = grid[top][j] + grid[bottom][j] + grid[i][left] + grid[i][right];
                }
            }
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[0].length; j++) {
                    newGrid[i][j] = Math.min(Math.max(newGrid[i][j], 0), 1);
                }
            }
            grid = newGrid;
        }
        return grid;
    }

    public static void main(String[] args) {
        int size = 100;
        double[][] grid = initialize_grid(size);
        while (true) {
            grid = evolve(grid, 10);
            for (double[] row : grid) {
                for (double val : row) {
                    System.out.print(val + " ");
                }
                System.out.println();
            }
        }
    }
}