import java.util.Random;

public class sample_1910 {

    public static float[][] updateGrid(float[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        float[][] newGrid = new float[rows][cols];
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                float sum = 0;
                for (int ii = i - 1; ii <= i + 1; ii++) {
                    for (int jj = j - 1; jj <= j + 1; jj++) {
                        sum += grid[ii][jj];
                    }
                }
                newGrid[i][j] = sum - grid[i][j];
            }
        }
        return newGrid;
    }

    public static float[][] simulateFlow(int iterations) {
        float[][] grid = new float[10][10];
        Random rand = new Random();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                grid[i][j] = rand.nextFloat();
            }
        }
        for (int _ = 0; _ < iterations; _++) {
            grid = updateGrid(grid);
        }
        return grid;
    }

    public static void main(String[] args) {
        float[][] result = simulateFlow(100);
        for (float[] row : result) {
            for (float value : row) {
                System.out.printf("%.6f ", value);
            }
            System.out.println();
        }
    }
}