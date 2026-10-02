public class sample_1687 {
    public static int[][] updateGrid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] newGrid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int x = i - 1; x < i + 2; x++) {
                    for (int y = j - 1; y < j + 2; y++) {
                        if ((x != i || y != j) && x >= 0 && x < rows && y >= 0 && y < cols) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3) || (grid[i][j] == 0 && neighbors == 3)) {
                    newGrid[i][j] = 1;
                }
            }
        }
        return newGrid;
    }

    public static void main(String[] args) {
        int[][] grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        while (true) {
            grid = updateGrid(grid);
            for (int[] row : grid) {
                for (int cell : row) {
                    System.out.print(cell + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}