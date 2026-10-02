import java.util.Arrays;

public class sample_2297 {
    public static double[][] initGrid(int size) {
        return new double[size][size];
    }

    public static double[][] updateGrid(double[][] grid, double diffusionRate) {
        int size = grid.length;
        double[][] newGrid = initGrid(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                double neighbors = 0.0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) {
                            continue;
                        }
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                            neighbors += grid[ni][nj];
                        }
                    }
                }
                newGrid[i][j] = grid[i][j] + diffusionRate * neighbors;
            }
        }
        return newGrid;
    }

    public static void main(String[] args) {
        int size = 100;
        double diffusionRate = 0.01;
        double[][] grid = initGrid(size);
        while (true) {
            grid = updateGrid(grid, diffusionRate);
        }
    }
}