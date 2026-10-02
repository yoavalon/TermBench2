import java.util.Arrays;

public class sample_2253 {
    public static int[][] update_state(int[][] grid) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int neighbors = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(i + 2, grid.length); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(j + 2, grid[0].length); y++) {
                        if (x != i || y != j) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                new_grid[i][j] = neighbors == 3 ? 1 : neighbors < 2 || neighbors > 3 ? 0 : grid[i][j];
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int[][] grid = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
        while (true) {
            grid = update_state(grid);
            for (int[] row : grid) {
                System.out.println(Arrays.toString(row).replaceAll("[\\[\\],]", ""));
            }
            System.out.println("-".repeat(grid[0].length * 2));
        }
    }
}