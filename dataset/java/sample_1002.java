import java.util.Arrays;

public class sample_1002 {
    static void update_grid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] new_grid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(rows, i + 2); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(cols, j + 2); y++) {
                        if ((x != i || y != j) && grid[x][y] == 1) {
                            neighbors++;
                        }
                    }
                }
                if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                    new_grid[i][j] = 1;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
        simulate(new_grid);
    }

    static void simulate(int[][] grid) {
        print_grid(grid);
        update_grid(grid);
    }

    static void print_grid(int[][] grid) {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell == 1 ? 'O' : ' ');
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[][] initial_grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        simulate(initial_grid);
    }
}