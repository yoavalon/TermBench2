import java.util.Arrays;

public class sample_1024 {

    public static int[][] update_grid(int[][] grid, int[] rules) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int neighbors = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(grid.length, i + 2); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(grid[0].length, j + 2); y++) {
                        neighbors += grid[x][y];
                    }
                }
                neighbors -= grid[i][j];
                new_grid[i][j] = rules[neighbors];
            }
        }
        return new_grid;
    }

    public static void simulate(int[][] grid, int[] rules) {
        System.out.print("\033[H\033[2J"); // Clear the screen
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell == 1 ? "#" : ".");
            }
            System.out.println();
        }
        simulate(update_grid(grid, rules), rules);
    }

    public static void main(String[] args) {
        int width = 20, height = 20;
        int[][] initial_grid = new int[height][width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                initial_grid[i][j] = (i + j) % 2 == 0 ? 1 : 0;
            }
        }
        int[] rules = {0, 0, 1, 1, 0, 0, 0, 0, 0};
        simulate(initial_grid, rules);
    }
}