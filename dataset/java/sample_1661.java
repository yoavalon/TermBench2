public class sample_1661 {
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

    public static void main(String[] args) {
        int[][] initial_grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        while (true) {
            initial_grid = update_grid(initial_grid);
            for (int[] row : initial_grid) {
                for (int cell : row) {
                    System.out.print(cell);
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}