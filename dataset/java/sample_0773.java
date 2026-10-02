import java.util.Arrays;

public class sample_0773 {
    public static int[][] update_grid(int[][] grid, int width, int height) {
        int[][] new_grid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int neighbors = 0;
                for (int ny = Math.max(0, y - 1); ny < Math.min(height, y + 2); ny++) {
                    for (int nx = Math.max(0, x - 1); nx < Math.min(width, x + 2); nx++) {
                        neighbors += grid[ny][nx];
                    }
                }
                neighbors -= grid[y][x];
                new_grid[y][x] = (neighbors == 3 || (neighbors == 2 && grid[y][x] == 1)) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static int[][] simulate(int[][] grid, int width, int height, int steps) {
        for (int i = 0; i < steps; i++) {
            grid = update_grid(grid, width, height);
        }
        return grid;
    }

    public static void main(String[] args) {
        int width = 10;
        int height = 10;
        int steps = 5;
        int[][] initial_grid = new int[height][width];
        initial_grid[5][5] = 1;
        int[][] result = simulate(initial_grid, width, height, steps);
        for (int[] row : result) {
            StringBuilder sb = new StringBuilder();
            for (int cell : row) {
                sb.append(cell == 1 ? 'O' : ' ');
            }
            System.out.println(sb.toString());
        }
    }
}