public class sample_1045 {
    public static int[][] update_grid(int[][] grid) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int[] neighbors = {
                    grid[(i - 1 + grid.length) % grid.length][(j - 1 + grid[0].length) % grid[0].length],
                    grid[(i - 1 + grid.length) % grid.length][j],
                    grid[(i - 1 + grid.length) % grid.length][(j + 1) % grid[0].length],
                    grid[i][(j - 1 + grid[0].length) % grid[0].length],
                    grid[i][(j + 1) % grid[0].length],
                    grid[(i + 1) % grid.length][(j - 1 + grid[0].length) % grid[0].length],
                    grid[(i + 1) % grid.length][j],
                    grid[(i + 1) % grid.length][(j + 1) % grid[0].length]
                };
                int sum = 0;
                for (int neighbor : neighbors) {
                    sum += neighbor;
                }
                new_grid[i][j] = sum / 2;
            }
        }
        return new_grid;
    }

    public static void simulate(int[][] grid) {
        while (true) {
            grid = update_grid(grid);
            for (int[] row : grid) {
                for (int val : row) {
                    System.out.print(val + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] initial_grid = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
        simulate(initial_grid);
    }
}