import java.util.Arrays;

public class sample_2873 {
    public static void updateGrid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] newGrid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                            neighbors += grid[ni][nj];
                        }
                    }
                }
                neighbors -= grid[i][j];
                newGrid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j])) ? 1 : 0;
            }
        }
        for (int i = 0; i < rows; i++) {
            System.arraycopy(newGrid[i], 0, grid[i], 0, cols);
        }
    }

    public static void main(String[] args) {
        int[][] grid = new int[50][50];
        grid[25][25] = 1;
        while (true) {
            updateGrid(grid);
        }
    }
}