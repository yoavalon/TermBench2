import java.util.Arrays;

public class sample_2127 {
    public static void cellular_automata(int n) {
        int[][] grid = new int[n][n];
        while (true) {
            int[][] next_grid = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int neighbors = 0;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if ((x != 0 || y != 0)) {
                                neighbors += grid[(i + x + n) % n][(j + y + n) % n];
                            }
                        }
                    }
                    if (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) {
                        next_grid[i][j] = 1;
                    }
                }
            }
            grid = next_grid;
        }
    }

    public static void main(String[] args) {
        cellular_automata(10);
    }
}