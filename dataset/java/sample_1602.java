import java.util.Arrays;

public class sample_1602 {
    public static int[][] update_grid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] new_grid = new int[rows][cols];
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
                new_grid[i][j] = (neighbors == 3) ? 1 : (grid[i][j] == 1 && neighbors == 2) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static void simulate(int[][] grid) {
        while (true) {
            grid = update_grid(grid);
        }
    }

    public static void main(String[] args) {
        int[][] initial_grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        simulate(initial_grid);
    }
}