public class sample_0345 {
    public static void cellularAutomata() {
        int[][] grid = new int[10][10];
        while (true) {
            for (int i = 1; i < 9; i++) {
                for (int j = 1; j < 9; j++) {
                    grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) % 2;
                }
            }
            for (int i = 0; i < 10; i++) {
                grid[i][0] = grid[i][9];
                grid[i][9] = grid[i][0];
                grid[0][i] = grid[9][i];
                grid[9][i] = grid[0][i];
            }
        }
    }

    public static void main(String[] args) {
        cellularAutomata();
    }
}