public class sample_2848 {
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
                        if (x != i || y != j) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                new_grid[i][j] = neighbors == 3 ? 1 : 0;
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