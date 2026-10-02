public class sample_0738 {
    public static int[][] update_grid(int[][] grid, int size) {
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
                new_grid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j])) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static int[][] simulate(int[][] grid, int size, int steps) {
        if (steps == 0) {
            return grid;
        }
        return simulate(update_grid(grid, size), size, steps - 1);
    }

    public static void main(String[] args) {
        int size = 10;
        int[][] initial_grid = new int[size][size];
        initial_grid[5][5] = 1;
        initial_grid[5][6] = 1;
        initial_grid[6][5] = 1;
        initial_grid[6][6] = 1;
        int[][] final_grid = simulate(initial_grid, size, 10);
        for (int[] row : final_grid) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }
}