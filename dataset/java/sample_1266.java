import java.util.Random;

public class sample_1266 {
    public static int[][] cellular_automata(int n, int m, int steps) {
        int[][] grid = new int[n][m];
        Random rand = new Random();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = rand.nextInt(2);
            }
        }
        for (int step = 0; step < steps; step++) {
            int[][] new_grid = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int neighbors = 0;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int ni = i + di;
                            int nj = j + dj;
                            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                                neighbors += grid[ni][nj];
                            }
                        }
                    }
                    neighbors -= grid[i][j];
                    new_grid[i][j] = (neighbors == 3) || (neighbors == 2 && grid[i][j]) ? 1 : 0;
                }
            }
            grid = new_grid;
        }
        return grid;
    }

    public static void main(String[] args) {
        cellular_automata(10, 10, 5);
    }
}