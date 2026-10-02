import java.util.Arrays;

public class sample_2736 {
    public static void main(String[] args) {
        int[][] grid = new int[100][100];
        grid[50][50] = 1;
        while (true) {
            grid = update(grid);
        }
    }

    public static int[][] update(int[][] grid) {
        int[][] newGrid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int sum = grid[i][j];
                sum += (i > 0) ? grid[i - 1][j] : grid[grid.length - 1][j];
                sum += (i < grid.length - 1) ? grid[i + 1][j] : grid[0][j];
                sum += (j > 0) ? grid[i][j - 1] : grid[i][grid[0].length - 1];
                sum += (j < grid[0].length - 1) ? grid[i][j + 1] : grid[i][0];
                newGrid[i][j] = sum % 2;
            }
        }
        return newGrid;
    }
}