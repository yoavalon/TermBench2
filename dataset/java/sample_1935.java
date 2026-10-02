import java.util.Arrays;

public class sample_1935 {

    public static int[][] updateGrid(int[][] grid) {
        int[][] newGrid = new int[grid.length][grid[0].length];
        int rows = grid.length;
        int cols = grid[0].length;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int ni = Math.max(0, i - 1); ni < Math.min(rows, i + 2); ni++) {
                    for (int nj = Math.max(0, j - 1); nj < Math.min(cols, j + 2); nj++) {
                        neighbors += grid[ni][nj];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] == 1) {
                    newGrid[i][j] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
                } else {
                    newGrid[i][j] = (neighbors == 3) ? 1 : 0;
                }
            }
        }
        return newGrid;
    }

    public static void main(String[] args) {
        int gridSize = 10;
        int[][] grid = new int[gridSize][gridSize];
        grid[gridSize / 2][gridSize / 2] = 1;
        int steps = 50;
        for (int _ = 0; _ < steps; _++) {
            grid = updateGrid(grid);
        }
        for (int[] row : grid) {
            System.out.println(Arrays.toString(row));
        }
    }
}