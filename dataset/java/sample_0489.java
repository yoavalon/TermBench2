public class sample_0489 {
    public static int[][] update_grid(int[][] grid, int width, int height) {
        int[][] new_grid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int neighbors = 0;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        if (dx == 0 && dy == 0) continue;
                        neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
                    }
                }
                if (grid[y][x] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[y][x] = 0;
                } else if (grid[y][x] == 0 && neighbors == 3) {
                    new_grid[y][x] = 1;
                } else {
                    new_grid[y][x] = grid[y][x];
                }
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int width = 10;
        int height = 10;
        int[][] grid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                grid[y][x] = (x + y) % 2;
            }
        }
        while (true) {
            grid = update_grid(grid, width, height);
        }
    }
}