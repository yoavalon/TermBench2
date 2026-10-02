public class sample_0402 {
    public static void update_cells(int[][] grid) {
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
                new_grid[i][j] = (neighbors == 3) ? 1 : grid[i][j];
            }
        }
        for (int i = 0; i < rows; i++) {
            System.arraycopy(new_grid[i], 0, grid[i], 0, cols);
        }
    }

    public static void display_grid(int[][] grid) {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print((cell == 1) ? "O" : ".");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        while (true) {
            display_grid(grid);
            update_cells(grid);
        }
    }
}