public class sample_0466 {
    public static boolean update_cell(int[][] grid, int i, int j, int size) {
        int neighbors = 0;
        for (int x = i - 1; x < i + 2; x++) {
            for (int y = j - 1; y < j + 2; y++) {
                if (0 <= x && x < size && 0 <= y && y < size && (x != i || y != j)) {
                    neighbors += grid[x][y];
                }
            }
        }
        return neighbors == 3 || (grid[i][j] == 1 && neighbors == 2);
    }

    public static int[][] step(int[][] grid) {
        int size = grid.length;
        int[][] new_grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                new_grid[i][j] = update_cell(grid, i, j, size) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int size = 10;
        int[][] grid = new int[size][size];
        grid[1][1] = 1;
        grid[2][2] = 1;
        grid[2][1] = 1;
        while (true) {
            grid = step(grid);
        }
    }
}