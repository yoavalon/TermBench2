public class sample_2747 {
    public static void cellular_automata(int x, int y, int steps) {
        int[][] grid = new int[y][x];
        for (int s = 0; s < steps; s++) {
            int[][] new_grid = new int[y][x];
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    int neighbors = 0;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            if (i + di >= 0 && i + di < y && j + dj >= 0 && j + dj < x) {
                                neighbors += grid[i + di][j + dj];
                            }
                        }
                    }
                    neighbors -= grid[i][j];
                    new_grid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j])) ? 1 : 0;
                }
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        cellular_automata(10, 10, 1000000);
    }
}