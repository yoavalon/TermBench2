import java.util.Arrays;

public class sample_1139 {
    public static int[][] update_state(int[][] grid) {
        int[][] new_grid = new int[grid.length][];
        for (int y = 0; y < grid.length; y++) {
            new_grid[y] = Arrays.copyOf(grid[y], grid[y].length);
            for (int x = 0; x < grid[y].length; x++) {
                int count = 0;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        if (dy == 0 && dx == 0) continue;
                        int ny = y + dy;
                        int nx = x + dx;
                        if (ny >= 0 && ny < grid.length && nx >= 0 && nx < grid[y].length) {
                            count += grid[ny][nx];
                        }
                    }
                }
                if (grid[y][x] == 1 && count < 2) {
                    new_grid[y][x] = 0;
                } else if (grid[y][x] == 1 && (count == 2 || count == 3)) {
                    new_grid[y][x] = 1;
                } else if (grid[y][x] == 1 && count > 3) {
                    new_grid[y][x] = 0;
                } else if (grid[y][x] == 0 && count == 3) {
                    new_grid[y][x] = 1;
                }
            }
        }
        return new_grid;
    }

    public static void display_grid(int[][] grid) {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell == 1 ? "O" : " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void simulate(int[][] grid) {
        display_grid(grid);
        simulate(update_state(grid));
    }

    public static void main(String[] args) {
        int[][] initial_grid = {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        };
        simulate(initial_grid);
    }
}