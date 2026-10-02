public class sample_1954 {
    public static double[][] update_grid(double[][] grid, int width, int height) {
        double[][] new_grid = new double[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                double neighbors = 0.0;
                for (int dy = -1; dy < 2; dy++) {
                    for (int dx = -1; dx < 2; dx++) {
                        if (dx == 0 && dy == 0) {
                            continue;
                        }
                        int nx = x + dx;
                        int ny = y + dy;
                        if (0 <= nx && nx < width && 0 <= ny && ny < height) {
                            neighbors += grid[ny][nx];
                        }
                    }
                }
                new_grid[y][x] = grid[y][x] + 0.1 * (neighbors - 2.0 * grid[y][x]);
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int width = 10;
        int height = 10;
        double[][] grid = new double[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                grid[y][x] = (x == y) ? 0.0 : 1.0;
            }
        }
        for (int i = 0; i < 100; i++) {
            grid = update_grid(grid, width, height);
        }
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                System.out.print(grid[y][x] + " ");
            }
            System.out.println();
        }
    }
}