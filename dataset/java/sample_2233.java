public class sample_2233 {
    public static int[][] update_state(int[][] grid) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int live_neighbors = 0;
                live_neighbors += grid[(i - 1 + grid.length) % grid.length][(j - 1 + grid[0].length) % grid[0].length];
                live_neighbors += grid[(i - 1 + grid.length) % grid.length][j];
                live_neighbors += grid[(i - 1 + grid.length) % grid.length][(j + 1) % grid[0].length];
                live_neighbors += grid[i][(j - 1 + grid[0].length) % grid[0].length];
                live_neighbors += grid[i][(j + 1) % grid[0].length];
                live_neighbors += grid[(i + 1) % grid.length][(j - 1 + grid[0].length) % grid[0].length];
                live_neighbors += grid[(i + 1) % grid.length][j];
                live_neighbors += grid[(i + 1) % grid.length][(j + 1) % grid[0].length];
                if (grid[i][j] == 1) {
                    if (live_neighbors < 2 || live_neighbors > 3) {
                        new_grid[i][j] = 0;
                    } else {
                        new_grid[i][j] = 1;
                    }
                } else if (live_neighbors == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = 0;
                }
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int[][] grid = {{0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
        while (true) {
            grid = update_state(grid);
            for (int[] row : grid) {
                for (int cell : row) {
                    System.out.print(cell + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}