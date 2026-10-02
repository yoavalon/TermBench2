public class sample_0929 {
    public static int cellular_automata(int[][] grid, int x, int y) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length) {
            return 0;
        }
        return grid[x][y] + cellular_automata(grid, x + 1, y) + cellular_automata(grid, x, y + 1);
    }

    public static void main(String[] args) {
        int[][] grid = new int[10][10];
        while (true) {
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[0].length; j++) {
                    grid[i][j] = cellular_automata(grid, i, j);
                }
            }
        }
    }
}