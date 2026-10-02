import java.util.Random;

public class sample_2834 {
    public static void update_state(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] new_grid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int ni = Math.max(0, i - 1); ni <= Math.min(rows - 1, i + 1); ni++) {
                    for (int nj = Math.max(0, j - 1); nj <= Math.min(cols - 1, j + 1); nj++) {
                        neighbors += grid[ni][nj];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] == 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_grid[i][j] = 0;
                    }
                } else if (neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            System.arraycopy(new_grid[i], 0, grid[i], 0, cols);
        }
    }

    public static void main(String[] args) {
        int size = 100;
        int[][] grid = new int[size][size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
        while (true) {
            update_state(grid);
        }
    }
}