import java.util.Random;

public class sample_0439 {
    public static void updateGrid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] newGrid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int ni = Math.max(0, i - 1); ni < Math.min(rows, i + 2); ni++) {
                    for (int nj = Math.max(0, j - 1); nj < Math.min(cols, j + 2); nj++) {
                        neighbors += grid[ni][nj];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    newGrid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            System.arraycopy(newGrid[i], 0, grid[i], 0, cols);
        }
    }

    public static void main(String[] args) {
        int size = 50;
        int[][] grid = new int[size][size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
        while (true) {
            updateGrid(grid);
        }
    }
}