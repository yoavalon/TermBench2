import java.util.Arrays;

public class sample_1079 {
    public static int[][] update(int[][] grid, int size) {
        int[][] new_grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                    }
                }
                new_grid[i][j] = (neighbors == 3) ? 1 : ((neighbors == 2) ? grid[i][j] : 0);
            }
        }
        return new_grid;
    }

    public static void simulate(int[][] grid, int size) {
        System.out.println(Arrays.deepToString(grid)
                .replace("], ", "\n")
                .replace("[", "")
                .replace("]", "")
                .replace(",", "")
                .replace("1", "#")
                .replace("0", " "));
        simulate(update(grid, size), size);
    }

    public static void main(String[] args) {
        int size = 10;
        int[][] grid = new int[size][size];
        grid[size / 2][size / 2] = 1;
        simulate(grid, size);
    }
}