public class sample_0456 {
    public static int[][] init_grid(int size) {
        int[][] grid = new int[size][size];
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                grid[y][x] = (x != 0 && x != size - 1 && y != 0 && y != size - 1) ? 0 : 1;
            }
        }
        return grid;
    }

    public static int[][] update_grid(int[][] grid) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int y = 1; y < grid.length - 1; y++) {
            for (int x = 1; x < grid[0].length - 1; x++) {
                int sum = 0;
                sum += grid[y - 1][x];
                sum += grid[y + 1][x];
                sum += grid[y][x - 1];
                sum += grid[y][x + 1];
                new_grid[y][x] = (sum >= 2) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static void simulate(int[][] grid) {
        while (true) {
            grid = update_grid(grid);
        }
    }

    public static void main(String[] args) {
        int size = 10;
        int[][] grid = init_grid(size);
        simulate(grid);
    }
}