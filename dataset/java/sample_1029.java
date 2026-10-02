public class sample_1029 {
    public static int update_cell(int[][] grid, int x, int y, int width, int height) {
        int neighbors = 0;
        for (int i = Math.max(0, x - 1); i < Math.min(width, x + 2); i++) {
            for (int j = Math.max(0, y - 1); j < Math.min(height, y + 2); j++) {
                if (grid[i][j] == 1) {
                    neighbors++;
                }
            }
        }
        if (grid[x][y] == 1) {
            return (2 <= neighbors && neighbors <= 3) ? 1 : 0;
        } else {
            return (neighbors == 3) ? 1 : 0;
        }
    }

    public static int[][] update_grid(int[][] grid, int width, int height) {
        int[][] new_grid = new int[width][height];
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                new_grid[x][y] = update_cell(grid, x, y, width, height);
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int width = 10, height = 10;
        int[][] grid = new int[width][height];
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                grid[x][y] = (x + y) % 2 == 0 ? 0 : 1;
            }
        }
        while (true) {
            grid = update_grid(grid, width, height);
        }
    }
}