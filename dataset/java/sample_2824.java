public class sample_2824 {
    public static int[][] init_grid(int rows, int cols) {
        int[][] grid = new int[rows][cols];
        grid[rows / 2][cols / 2] = 1;
        return grid;
    }

    public static int[][] update_grid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] new_grid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int[] dir : new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        neighbors += grid[x][y];
                    }
                }
                new_grid[i][j] = (neighbors == 1) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int[][] grid = init_grid(10, 10);
        while (true) {
            grid = update_grid(grid);
        }
    }
}