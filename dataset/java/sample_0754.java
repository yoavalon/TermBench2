public class sample_0754 {
    public static int[][] update_grid(int[][] grid, int width, int height) {
        int[][] new_grid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int neighbors = 0;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        if (dx != 0 || dy != 0) {
                            neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
                        }
                    }
                }
                new_grid[y][x] = (neighbors == 3) || (grid[y][x] == 1 && neighbors == 2) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static int[][] simulate(int[][] grid, int width, int height, int steps) {
        if (steps == 0) {
            return grid;
        }
        return simulate(update_grid(grid, width, height), width, height, steps - 1);
    }

    public static void main(String[] args) {
        int width = 5;
        int height = 5;
        int steps = 5;
        int[][] grid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                grid[y][x] = (x + y) % 2 == 0 ? 1 : 0;
            }
        }
        int[][] final_grid = simulate(grid, width, height, steps);
        for (int[] row : final_grid) {
            for (int cell : row) {
                System.out.print(cell == 1 ? 'O' : ' ');
            }
            System.out.println();
        }
    }
}