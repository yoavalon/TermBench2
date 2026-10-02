import java.util.Arrays;

public class sample_2857 {
    public static int[][] update_state(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] new_grid = new int[rows][cols];
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int[] neighbors = new int[4];
                int count = 0;
                if (r - 1 >= 0) neighbors[count++] = grid[r - 1][c];
                if (r + 1 < rows) neighbors[count++] = grid[r + 1][c];
                if (c - 1 >= 0) neighbors[count++] = grid[r][c - 1];
                if (c + 1 < cols) neighbors[count++] = grid[r][c + 1];
                int sum = Arrays.stream(neighbors).sum();
                new_grid[r][c] = (sum == 3) ? 1 : grid[r][c];
            }
        }
        return new_grid;
    }

    public static void run_simulation() {
        int[][] grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        while (true) {
            grid = update_state(grid);
            for (int[] row : grid) {
                for (int cell : row) {
                    System.out.print((cell == 1) ? 'O' : ' ');
                }
                System.out.println();
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        run_simulation();
    }
}