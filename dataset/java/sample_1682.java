import java.util.Arrays;

public class sample_1682 {
    public static int[][] update_state(int[][] grid) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int neighbors = 0;
                for (int[] direction : new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                    int x = i + direction[0];
                    int y = j + direction[1];
                    if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length) {
                        neighbors += grid[x][y];
                    }
                }
                new_grid[i][j] = (neighbors == 3) || (grid[i][j] == 1 && neighbors == 2) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static void simulate(int[][] grid) {
        while (true) {
            grid = update_state(grid);
            for (int[] row : grid) {
                System.out.println(Arrays.toString(row).replaceAll("\\[|\\],", "").replaceAll(", ", " "));
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] initial_grid = {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        };
        simulate(initial_grid);
    }
}