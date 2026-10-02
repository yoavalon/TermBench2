import java.util.Arrays;
import java.util.Random;

public class sample_1640 {
    public static int[][] updateGrid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] newGrid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int ii = Math.max(0, i - 1); ii < Math.min(rows, i + 2); ii++) {
                    for (int jj = Math.max(0, j - 1); jj < Math.min(cols, j + 2); jj++) {
                        neighbors += grid[ii][jj];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] == 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        newGrid[i][j] = 0;
                    } else {
                        newGrid[i][j] = 1;
                    }
                } else if (neighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        return newGrid;
    }

    public static void main(String[] args) {
        int size = 50;
        int[][] grid = new int[size][size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = rand.nextInt(2);
            }
        }
        while (true) {
            grid = updateGrid(grid);
        }
    }
}