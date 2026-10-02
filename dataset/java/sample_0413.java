import java.util.Arrays;

public class sample_0413 {
    public static int[][] initialize_grid(int rows, int cols) {
        return new int[rows][cols];
    }

    public static int[][] update_grid(int[][] grid) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int neighbors = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && !(x == i && y == j)) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors < 2 || neighbors > 3) ? 0 : grid[i][j];
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int rows = 50;
        int cols = 50;
        int[][] grid = initialize_grid(rows, cols);
        while (true) {
            grid = update_grid(grid);
        }
    }
}