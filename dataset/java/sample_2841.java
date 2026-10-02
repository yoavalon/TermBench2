import java.util.HashMap;
import java.util.Map;

public class sample_2841 {
    public static int[][] update_grid(int[][] grid, Map<String, Integer> rules) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int[] neighbors = new int[8];
                int index = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(grid.length, i + 2); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(grid[0].length, j + 2); y++) {
                        if ((x != i) || (y != j)) {
                            neighbors[index++] = grid[x][y];
                        }
                    }
                }
                java.util.Arrays.sort(neighbors);
                new_grid[i][j] = rules.getOrDefault(java.util.Arrays.toString(neighbors), 0);
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int[][] grid = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
        Map<String, Integer> rules = new HashMap<>();
        rules.put("[0, 0, 0, 0, 0, 0, 0, 0]", 0);
        rules.put("[1, 1, 1, 1, 1, 1, 1, 1]", 1);
        rules.put("[0, 0, 0, 1, 1, 1, 0, 0]", 1);
        while (true) {
            grid = update_grid(grid, rules);
        }
    }
}