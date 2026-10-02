public class sample_0483 {
    public static int[][] updateGrid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] newGrid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(rows, i + 2); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(cols, j + 2); y++) {
                        if ((x, y) != (i, j)) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                if (grid[i][j] == 1) {
                    newGrid[i][j] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
                } else {
                    newGrid[i][j] = (neighbors == 3) ? 1 : 0;
                }
            }
        }
        return newGrid;
    }

    public static void simulate(int[][] grid) {
        while (true) {
            grid = updateGrid(grid);
        }
    }

    public static void main(String[] args) {
        int[][] initialGrid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        simulate(initialGrid);
    }
}