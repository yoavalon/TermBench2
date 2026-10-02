public class sample_0702 {
    public static int[][] updateGrid(int[][] grid, int size) {
        int[][] newGrid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(size, i + 2); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(size, j + 2); y++) {
                        if (x != i || y != j) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                newGrid[i][j] = (neighbors == 3) ? 1 : (neighbors == 2) ? grid[i][j] : 0;
            }
        }
        return newGrid;
    }

    public static int[][] simulate(int size, int steps) {
        int[][] grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = (i % 2 == 0) ? 1 : 0;
            }
        }
        for (int _ = 0; _ < steps; _++) {
            grid = updateGrid(grid, size);
        }
        return grid;
    }

    public static void main(String[] args) {
        int size = 5;
        int steps = 10;
        int[][] result = simulate(size, steps);
        for (int[] row : result) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }
}