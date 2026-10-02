public class sample_2738 {
    public static void cellular_automata() {
        int[][] grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        while (true) {
            int[][] new_grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int live_neighbors = 0;
                    for (int x = i - 1; x < i + 2; x++) {
                        for (int y = j - 1; y < j + 2; y++) {
                            if (0 <= x && x < 3 && 0 <= y && y < 3 && (x != i || y != j) && grid[x][y] == 1) {
                                live_neighbors++;
                            }
                        }
                    }
                    new_grid[i][j] = (live_neighbors == 2) ? 1 : 0;
                }
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        cellular_automata();
    }
}