public class sample_2826 {
    public static int[][] initialize_grid(int size) {
        int[][] grid = new int[size][size];
        grid[size / 2][size / 2] = 1;
        return grid;
    }

    public static int[][] update_grid(int[][] grid) {
        int[][] new_grid = new int[grid.length][];
        for (int i = 0; i < grid.length; i++) {
            new_grid[i] = grid[i].clone();
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                int neighbors = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < grid.length && y >= 0 && y < grid[i].length && !(x == i && y == j)) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int size = 50;
        int[][] grid = initialize_grid(size);
        while (true) {
            grid = update_grid(grid);
        }
    }
}