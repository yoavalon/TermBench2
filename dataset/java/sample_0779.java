import java.util.Arrays;

public class sample_0779 {
    public static int[][] updateGrid(int[][] grid, int width, int height) {
        int[][] newGrid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int neighbors = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx != 0 || dy != 0) {
                            neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
                        }
                    }
                }
                newGrid[y][x] = (neighbors == 3) ? 1 : grid[y][x];
            }
        }
        return newGrid;
    }

    public static int[][] simulate(int[][] grid, int width, int height, int steps) {
        if (steps == 0) {
            return grid;
        }
        return simulate(updateGrid(grid, width, height), width, height, steps - 1);
    }

    public static void main(String[] args) {
        int width = 10, height = 10, steps = 5;
        int[][] initialGrid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                initialGrid[y][x] = (x == y) ? 1 : 0;
            }
        }
        int[][] finalGrid = simulate(initialGrid, width, height, steps);
        for (int[] row : finalGrid) {
            System.out.println(Arrays.toString(row).replaceAll("[\\[\\],]", ""));
        }
    }
}