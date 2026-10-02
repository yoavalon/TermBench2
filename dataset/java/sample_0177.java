import java.util.Arrays;

public class sample_0177 {
    public static void main(String[] args) {
        int size = 10;
        int[][] grid = initGrid(size);
        int steps = 50;
        for (int _ = 0; _ < steps; _++) {
            grid = updateGrid(grid);
        }
        printGrid(grid);
    }

    public static int[][] initGrid(int size) {
        int[][] grid = new int[size][size];
        grid[size / 2][size / 2] = 1;
        return grid;
    }

    public static int[][] updateGrid(int[][] grid) {
        int[][] newGrid = Arrays.stream(grid).map(row -> row.clone()).toArray(int[][]::new);
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int neighbors = countNeighbors(grid, i, j);
                if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    newGrid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        return newGrid;
    }

    public static int countNeighbors(int[][] grid, int i, int j) {
        int count = 0;
        for (int x = Math.max(0, i - 1); x < Math.min(grid.length, i + 2); x++) {
            for (int y = Math.max(0, j - 1); y < Math.min(grid[0].length, j + 2); y++) {
                count += grid[x][y];
            }
        }
        count -= grid[i][j];
        return count;
    }

    public static void printGrid(int[][] grid) {
        for (int[] row : grid) {
            System.out.println(Arrays.toString(row));
        }
    }
}