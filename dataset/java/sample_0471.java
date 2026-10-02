public class sample_0471 {
    public static int[][] initialize_grid(int size) {
        int[][] grid = new int[size][size];
        grid[size / 2][size / 2] = 1;
        return grid;
    }

    public static int[][] update_grid(int[][] grid) {
        int size = grid.length;
        int[][] new_grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(size, i + 2); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(size, j + 2); y++) {
                        neighbors += grid[x][y];
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
        int size = 10;
        int[][] grid = initialize_grid(size);
        while (true) {
            grid = update_grid(grid);
        }
    }
}