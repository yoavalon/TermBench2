import java.util.Arrays;

public class sample_0481 {
    public static int[][] initialize_grid(int size) {
        int[][] grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = 0;
            }
        }
        return grid;
    }

    public static int[][] update_grid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] new_grid = new int[rows][cols];
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                int neighbors = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        neighbors += grid[i + di][j + dj];
                    }
                }
                neighbors -= grid[i][j];
                if (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = 0;
                }
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int size = 50;
        int[][] grid = initialize_grid(size);
        while (true) {
            grid = update_grid(grid);
        }
    }
}