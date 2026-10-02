public class sample_1675 {
    public static int[][] update_state(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] new_grid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(rows, i + 2); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(cols, j + 2); y++) {
                        if ((x, y) != (i, j)) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors == 2) ? grid[i][j] : 0;
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int[][] grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        while (true) {
            grid = update_state(grid);
            for (int[] row : grid) {
                StringBuilder sb = new StringBuilder();
                for (int cell : row) {
                    sb.append((cell == 1) ? 'O' : '.');
                }
                System.out.println(sb.toString());
            }
            System.out.println();
        }
    }
}