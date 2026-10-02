import java.util.Random;

public class sample_1333 {

    public static int[][] update_grid(int[][] grid) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 1; i < grid.length - 1; i++) {
            for (int j = 1; j < grid[0].length - 1; j++) {
                int neighbors = countNeighbors(grid, i, j);
                if (grid[i][j] != 0 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = grid[i][j];
                }
            }
        }
        return new_grid;
    }

    private static int countNeighbors(int[][] grid, int i, int j) {
        int count = 0;
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (x == 0 && y == 0) continue;
                count += grid[i + x][j + y];
            }
        }
        return count;
    }

    public static int[][] simulate(int[][] grid, int steps) {
        for (int step = 0; step < steps; step++) {
            grid = update_grid(grid);
        }
        return grid;
    }

    public static void main(String[] args) {
        int size = 50;
        int[][] grid = new int[size][size];
        Random rand = new Random();
        for (int i = 20; i < 25; i++) {
            for (int j = 20; j < 25; j++) {
                grid[i][j] = rand.nextInt(2);
            }
        }
        int[][] final_grid = simulate(grid, 100);
        for (int i = 0; i < final_grid.length; i++) {
            for (int j = 0; j < final_grid[0].length; j++) {
                System.out.print(final_grid[i][j] + " ");
            }
            System.out.println();
        }
    }
}