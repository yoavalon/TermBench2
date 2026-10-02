public class sample_0979 {
    public static void fluid_dynamics(int[][] grid) {
        int size = grid.length;
        int[][] next_grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(size, i + 2); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(size, j + 2); y++) {
                        neighbors += grid[x][y];
                    }
                }
                next_grid[i][j] = neighbors > 4 ? 1 : 0;
            }
        }
        fluid_dynamics(next_grid);
    }

    public static void main(String[] args) {
        int[][] grid = new int[10][10];
        grid[5][5] = 1;
        fluid_dynamics(grid);
    }
}