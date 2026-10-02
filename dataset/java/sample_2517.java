public class sample_2517 {
    public static int[][] update_grid(int[][] grid) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int neighbors = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) {
                            continue;
                        }
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[0].length) {
                            neighbors += grid[ni][nj];
                        }
                    }
                }
                if (grid[i][j] == 1) {
                    new_grid[i][j] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
                } else {
                    new_grid[i][j] = (neighbors == 3) ? 1 : 0;
                }
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int[][] initial_grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        for (int _ = 0; _ < 10; _++) {
            initial_grid = update_grid(initial_grid);
            for (int[] row : initial_grid) {
                for (int cell : row) {
                    System.out.print(cell == 1 ? '#' : ' ');
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}