import java.util.Arrays;

public class sample_0789 {
    public static int[][] updateGrid(int[][] grid, int width, int height) {
        int[][] newGrid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int neighbors = 0;
                for (int[] d : new int[][]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}) {
                    neighbors += grid[(y + d[0] + height) % height][(x + d[1] + width) % width];
                }
                newGrid[y][x] = (neighbors == 3 || (grid[y][x] == 1 && neighbors == 2)) ? 1 : 0;
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
        int width = 10, height = 10;
        int[][] initialGrid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                initialGrid[y][x] = (x % 2 == 0) ? 1 : 0;
            }
        }
        int steps = 5;
        int[][] finalGrid = simulate(initialGrid, width, height, steps);
        for (int[] row : finalGrid) {
            System.out.println(Arrays.toString(row).replaceAll("\\[|\\]", ""));
        }
    }
}