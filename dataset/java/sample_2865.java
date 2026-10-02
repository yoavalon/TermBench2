import java.util.Arrays;

public class sample_2865 {
    public static int[][] update_grid(int[][] grid) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int neighbors = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(grid.length, i + 2); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(grid[0].length, j + 2); y++) {
                        if (x != i || y != j) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                new_grid[i][j] = (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static void cellular_automata() {
        int[][] grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        while (true) {
            grid = update_grid(grid);
            for (int[] row : grid) {
                System.out.println(Arrays.toString(row).replace("[", "").replace("]", "").replace(",", ""));
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        cellular_automata();
    }
}