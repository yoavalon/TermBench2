public class sample_0740 {
    public static int[][] update_state(int[][] grid, int width, int height) {
        int[][] new_grid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int neighbors = 0;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        if (dy == 0 && dx == 0) {
                            continue;
                        }
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                            neighbors += grid[ny][nx];
                        }
                    }
                }
                if (grid[y][x] == 1) {
                    new_grid[y][x] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
                } else {
                    new_grid[y][x] = (neighbors == 3) ? 1 : 0;
                }
            }
        }
        return new_grid;
    }

    public static int[][] simulate(int[][] grid, int width, int height, int steps) {
        if (steps == 0) {
            return grid;
        } else {
            return simulate(update_state(grid, width, height), width, height, steps - 1);
        }
    }

    public static void main(String[] args) {
        int width = 50;
        int height = 50;
        int steps = 100;
        int[][] grid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                grid[y][x] = ((x + y) % 2 == 0) ? 1 : 0;
            }
        }
        int[][] final_grid = simulate(grid, width, height, steps);
        for (int[] row : final_grid) {
            StringBuilder sb = new StringBuilder();
            for (int cell : row) {
                sb.append(cell == 1 ? 'O' : ' ');
            }
            System.out.println(sb.toString());
        }
    }
}