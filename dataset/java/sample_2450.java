public class sample_2450 {
    public static int[][] simulate_cells(int rows, int cols, int steps) {
        int[][] grid = new int[rows][cols];
        for (int step = 0; step < steps; step++) {
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
                    if (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) {
                        new_grid[i][j] = 1;
                    }
                }
            }
            grid = new_grid;
        }
        return grid;
    }

    public static void main(String[] args) {
        simulate_cells(10, 10, 5);
    }
}