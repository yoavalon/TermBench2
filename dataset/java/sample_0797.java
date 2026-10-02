public class sample_0797 {
    public static int[][] updateGrid(int[][] grid) {
        int[][] newGrid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int count = 0;
                for (int x = i - 1; x < i + 2; x++) {
                    for (int y = j - 1; y < j + 2; y++) {
                        if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && (x != i || y != j)) {
                            count += grid[x][y];
                        }
                    }
                }
                newGrid[i][j] = (grid[i][j] == 1 && (count == 2 || count == 3)) || (count == 3) ? 1 : 0;
            }
        }
        return newGrid;
    }

    public static int[][] simulate(int[][] grid, int steps) {
        for (int _ = 0; _ < steps; _++) {
            grid = updateGrid(grid);
        }
        return grid;
    }

    public static void main(String[] args) {
        int[][] initialGrid = {{0, 0, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}};
        int[][] finalGrid = simulate(initialGrid, 10);
        for (int[] row : finalGrid) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }
}