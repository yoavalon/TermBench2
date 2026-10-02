public class sample_2754 {
    public static void cellular_automata(int n, int m) {
        int[][] grid = new int[n][m];
        while (true) {
            int[][] new_grid = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int state = grid[i][j];
                    int neighbors = 0;
                    for (int x = i - 1; x <= i + 1; x++) {
                        for (int y = j - 1; y <= j + 1; y++) {
                            if (x >= 0 && x < n && y >= 0 && y < m) {
                                neighbors += grid[x][y];
                            }
                        }
                    }
                    neighbors -= state;
                    new_grid[i][j] = (neighbors == 3 || (state == 1 && neighbors == 2)) ? 1 : 0;
                }
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        cellular_automata(10, 10);
    }
}