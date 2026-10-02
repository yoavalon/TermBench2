import java.util.Arrays;
import java.util.Random;

public class sample_1017 {
    public static int[][] update_grid(int[][] grid) {
        int size = grid.length;
        int[][] new_grid = new int[size][size];
        for (int x = 0; x < size; x++) {
            for (int y = 0; y < size; y++) {
                int neighbors = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx != 0 || dy != 0) {
                            neighbors += grid[(x + dx + size) % size][(y + dy + size) % size];
                        }
                    }
                }
                new_grid[x][y] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static void simulate(int[][] grid) {
        Random random = new Random();
        if (grid.length == 0) {
            grid = new int[10][10];
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    grid[i][j] = random.nextInt(2);
                }
            }
        }
        for (int[] row : grid) {
            System.out.println(Arrays.toString(row).replaceAll("\\[|\\]", ""));
        }
        simulate(update_grid(grid));
    }

    public static void main(String[] args) {
        simulate(new int[0][0]);
    }
}