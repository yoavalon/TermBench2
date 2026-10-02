import java.util.Random;

public class sample_2847 {
    public static int[][] update_grid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] new_grid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = grid[i][(j - 1 + cols) % cols] + grid[i][(j + 1) % cols] + grid[(i - 1 + rows) % rows][j] + grid[(i + 1) % rows][j] + grid[(i - 1 + rows) % rows][(j - 1 + cols) % cols] + grid[(i - 1 + rows) % rows][(j + 1) % cols] + grid[(i + 1) % rows][(j - 1 + cols) % cols] + grid[(i + 1) % rows][(j + 1) % cols];
                if (grid[i][j] == 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_grid[i][j] = 0;
                    }
                } else if (neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int grid_size = 10;
        int[][] grid = new int[grid_size][grid_size];
        Random random = new Random();
        for (int i = 0; i < grid_size; i++) {
            for (int j = 0; j < grid_size; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
        while (true) {
            grid = update_grid(grid);
            for (int[] row : grid) {
                for (int cell : row) {
                    System.out.print(cell + " ");
                }
                System.out.println();
            }
            System.out.println("--------------------");
        }
    }
}