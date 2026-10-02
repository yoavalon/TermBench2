import java.util.Arrays;

public class sample_1085 {
    public static int[][] updateGrid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] newGrid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(rows, i + 2); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(cols, j + 2); y++) {
                        if (x != i || y != j) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                newGrid[i][j] = (neighbors == 3) || (grid[i][j] == 1 && neighbors == 2) ? 1 : 0;
            }
        }
        return newGrid;
    }

    public static void simulate(int[][] grid) {
        simulate(updateGrid(grid));
    }

    public static void main(String[] args) {
        int gridSize = 10;
        int[][] initialGrid = new int[gridSize][gridSize];
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                initialGrid[i][j] = (i % 2 == 0 || j % 2 == 0) ? 0 : 1;
            }
        }
        simulate(initialGrid);
    }
}