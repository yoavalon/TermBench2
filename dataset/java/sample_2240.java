public class sample_2240 {
    public static double[][] update_grid(double[][] grid, int width, int height) {
        double[][] new_grid = new double[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int neighbors = 0;
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        if (i == 0 && j == 0) {
                            continue;
                        }
                        int nx = (x + i) % width;
                        int ny = (y + j) % height;
                        neighbors += grid[ny][nx];
                    }
                }
                new_grid[y][x] = neighbors / 9.0;
            }
        }
        return new_grid;
    }

    public static void simulate(int width, int height) {
        double[][] grid = new double[height][width];
        while (true) {
            grid = update_grid(grid, width, height);
        }
    }

    public static void main(String[] args) {
        simulate(100, 100);
    }
}