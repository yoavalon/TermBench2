import java.util.Arrays;

public class sample_0136 {
    public static void main(String[] args) {
        int gridSize = 50;
        int iterations = 100;
        int[][] grid = initializeGrid(gridSize);
        for (int i = 0; i < iterations; i++) {
            grid = updateGrid(grid);
        }
        printGrid(grid);
    }

    public static int[][] initializeGrid(int size) {
        return new int[size][size];
    }

    public static int[][] updateGrid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] newGrid = Arrays.copyOf(grid, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = countNeighbors(grid, i, j);
                if (grid[i][j] == 0 && neighbors == 3) {
                    newGrid[i][j] = 1;
                } else if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    newGrid[i][j] = 0;
                }
            }
        }
        return newGrid;
    }

    private static int countNeighbors(int[][] grid, int i, int j) {
        int count = 0;
        int rows = grid.length;
        int cols = grid[0].length;
        for (int x = Math.max(0, i - 1); x <= Math.min(rows - 1, i + 1); x++) {
            for (int y = Math.max(0, j - 1); y <= Math.min(cols - 1, j + 1); y++) {
                count += grid[x][y];
            }
        }
        count -= grid[i][j];
        return count;
    }

    private static void printGrid(int[][] grid) {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }
}