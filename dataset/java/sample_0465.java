public class sample_0465 {
    public static int[][] initialize_grid(int size) {
        int[][] grid = new int[size][size];
        grid[size / 2][size / 2] = 1;
        return grid;
    }

    public static int[][] update_grid(int[][] grid) {
        int[][] new_grid = new int[grid.length][grid.length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                int neighbors = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(grid.length, i + 2); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(grid.length, j + 2); y++) {
                        if (x != i || y != j) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                if (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) {
                    new_grid[i][j] = 1;
                }
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int grid_size = 10;
        int[][] grid = initialize_grid(grid_size);
        while (true) {
            grid = update_grid(grid);
        }
    }
}