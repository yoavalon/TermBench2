import java.util.Arrays;

public class sample_1617 {
    static int[][] update_state(int[][] grid) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 1; i < grid.length - 1; i++) {
            for (int j = 1; j < grid[i].length - 1; j++) {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        neighbors += grid[i + x][j + y];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int size = 50;
        int[][] grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = (int) (Math.random() * 2);
            }
        }
        while (true) {
            grid = update_state(grid);
        }
    }
}