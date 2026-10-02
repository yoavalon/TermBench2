public class sample_1061 {
    public static int[][] update_grid(int[][] grid) {
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int sum = 0;
                int count = 0;
                for (int di = -1; di < 2; di++) {
                    for (int dj = -1; dj < 2; dj++) {
                        if (0 <= i + di && i + di < grid.length && 0 <= j + dj && j + dj < grid[0].length) {
                            sum += grid[i + di][j + dj];
                            count++;
                        }
                    }
                }
                new_grid[i][j] = sum / count;
            }
        }
        return new_grid;
    }

    public static void display(int[][] grid) {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void simulate(int[][] grid) {
        display(grid);
        simulate(update_grid(grid));
    }

    public static void main(String[] args) {
        int[][] grid = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
        simulate(grid);
    }
}