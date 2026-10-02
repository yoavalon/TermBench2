public class sample_0342 {
    public static void simulate_flow(int width, int height) {
        int[][] grid = new int[height][width];
        while (true) {
            int[][] new_grid = new int[height][width];
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    int sum = 0;
                    for (int[] dir : new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                        int ny = (y + dir[0] + height) % height;
                        int nx = (x + dir[1] + width) % width;
                        sum += grid[ny][nx];
                    }
                    new_grid[y][x] = sum / 4;
                }
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        simulate_flow(10, 10);
    }
}