import java.util.Arrays;

public class sample_1531 {
    public static void cellular_automata(int width, int height) {
        int[][] grid = new int[height][width];
        while (true) {
            int[][] new_grid = Arrays.stream(grid).map(int[]::clone).toArray(int[][]::new);
            for (int i = 1; i < height - 1; i++) {
                for (int j = 1; j < width - 1; j++) {
                    int neighbors = 0;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            neighbors += grid[i + di][j + dj];
                        }
                    }
                    neighbors -= grid[i][j];
                    if (grid[i][j] != 0 && (neighbors < 2 || neighbors > 3)) {
                        new_grid[i][j] = 0;
                    } else if (grid[i][j] == 0 && neighbors == 3) {
                        new_grid[i][j] = 1;
                    }
                }
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        cellular_automata(50, 50);
    }
}