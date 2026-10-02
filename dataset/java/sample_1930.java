import java.util.Random;

public class sample_1930 {
    public static void main(String[] args) {
        int steps = 50;
        int precision = 3;
        double[][] result = run_simulation(steps, precision);
        printGrid(result);
    }

    public static double[][] update_grid(double[][] grid, int precision) {
        int size = grid.length;
        double[][] new_grid = new double[size][size];
        for (int i = 1; i < size - 1; i++) {
            for (int j = 1; j < size - 1; j++) {
                double avg = calculateAverage(grid, i, j);
                new_grid[i][j] = Math.round(avg * Math.pow(10, precision)) / Math.pow(10, precision);
            }
        }
        return new_grid;
    }

    public static double calculateAverage(double[][] grid, int i, int j) {
        double sum = 0;
        for (int x = i - 1; x <= i + 1; x++) {
            for (int y = j - 1; y <= j + 1; y++) {
                sum += grid[x][y];
            }
        }
        return sum / 9;
    }

    public static double[][] run_simulation(int steps, int precision) {
        int gridSize = 10;
        double[][] grid = new double[gridSize][gridSize];
        Random random = new Random();
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                grid[i][j] = random.nextDouble();
            }
        }
        for (int _ = 0; _ < steps; _++) {
            grid = update_grid(grid, precision);
        }
        return grid;
    }

    public static void printGrid(double[][] grid) {
        for (double[] row : grid) {
            for (double value : row) {
                System.out.printf("%.3f ", value);
            }
            System.out.println();
        }
    }
}