public class sample_1093 {
    public static int[][] update_state(int[][] grid, int x, int y, int size) {
        if (x < 0 || x >= size || y < 0 || y >= size) {
            return grid;
        }
        int neighbors = 0;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    neighbors += grid[nx][ny];
                }
            }
        }
        if (grid[x][y] == 1) {
            if (neighbors < 2 || neighbors > 3) {
                grid[x][y] = 0;
            }
        } else if (neighbors == 3) {
            grid[x][y] = 1;
        }
        if (x < size - 1) {
            return update_state(grid, x + 1, y, size);
        } else if (y < size - 1) {
            return update_state(grid, 0, y + 1, size);
        } else {
            return grid;
        }
    }

    public static void main(String[] args) {
        int size = 10;
        int[][] grid = new int[size][size];
        grid[size / 2][size / 2] = 1;
        while (true) {
            grid = update_state(grid, 0, 0, size);
        }
    }
}