public class sample_0490 {
    public static int[][] update_grid(int[][] grid, int width, int height) {
        int[][] new_grid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int neighbors = 0;
                for (int dx = -1; dx < 2; dx++) {
                    for (int dy = -1; dy < 2; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        neighbors += grid[(y + dy) % height][(x + dx) % width];
                    }
                }
                if (grid[y][x] == 1) {
                    new_grid[y][x] = neighbors == 2 || neighbors == 3 ? 1 : 0;
                } else {
                    new_grid[y][x] = neighbors == 3 ? 1 : 0;
                }
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int width = 50;
        int height = 50;
        int[][] grid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                grid[y][x] = (x + y) % 2 == 0 ? 1 : 0;
            }
        }
        while (true) {
            grid = update_grid(grid, width, height);
        }
    }
}