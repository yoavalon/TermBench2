public class sample_0467 {
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
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                int neighbors = 0;
                for (int x = -1; x < 2; x++) {
                    for (int y = -1; y < 2; y++) {
                        if (x == 0 && y == 0) {
                            continue;
                        }
                        int ni = i + x;
                        int nj = j + y;
                        if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[i].length) {
                            neighbors += grid[ni][nj];
                        }
                    }
                }
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
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