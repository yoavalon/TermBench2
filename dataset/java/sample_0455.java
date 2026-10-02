import java.util.Random;

public class sample_0455 {
    public static void main(String[] args) {
        int gridSize = 50;
        int[][] grid = generateRandomGrid(gridSize, gridSize);
        while (true) {
            grid = updateGrid(grid, gridSize, gridSize);
        }
    }

    public static int[][] generateRandomGrid(int rows, int cols) {
        int[][] grid = new int[rows][cols];
        Random random = new Random();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
        return grid;
    }

    public static int[][] updateGrid(int[][] grid, int rows, int cols) {
        int[][] newGrid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = countNeighbors(grid, rows, cols, i, j);
                if (grid[i][j] == 1 && (neighbors == 3 || neighbors == 4)) {
                    newGrid[i][j] = 1;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        return newGrid;
    }

    public static int countNeighbors(int[][] grid, int rows, int cols, int i, int j) {
        int count = 0;
        for (int x = Math.max(0, i - 1); x < Math.min(rows, i + 2); x++) {
            for (int y = Math.max(0, j - 1); y < Math.min(cols, j + 2); y++) {
                if (x != i || y != j) {
                    count += grid[x][y];
                }
            }
        }
        return count;
    }
}