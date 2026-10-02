public class sample_0710 {
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
                new_grid[i][j] = (neighbors == 3) || (grid[i][j] == 1 && neighbors == 2) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static int[][] simulate(int[][] grid, int steps) {
        for (int _ = 0; _ < steps; _++) {
            grid = update_grid(grid);
        }
        return grid;
    }

    public static void main(String[] args) {
        int[][] initial_grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        int steps = 5;
        int[][] final_grid = simulate(initial_grid, steps);
        for (int[] row : final_grid) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}