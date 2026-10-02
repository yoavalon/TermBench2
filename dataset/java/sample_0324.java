public class sample_0324 {
    public static void simulate() {
        int[][] grid = new int[50][50];
        while (true) {
            int[][] new_grid = new int[50][50];
            for (int i = 1; i < 49; i++) {
                for (int j = 1; j < 49; j++) {
                    int neighbors = grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1];
                    new_grid[i][j] = (neighbors == 2) ? 1 : 0;
                }
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}