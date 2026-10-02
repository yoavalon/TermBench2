public class sample_0668 {
    public static void main(String[] args) {
        int[][] grid = {{0, 0, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}};
        int[][] result = cellular_automata(grid, 10);
        for (int[] row : result) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }

    public static int[][] cellular_automata(int[][] grid, int steps) {
        if (steps == 0) {
            return grid;
        }
        int[][] new_grid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int neighbors = 0;
                for (int[] direction : new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                    int x = i + direction[0];
                    int y = j + direction[1];
                    if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length) {
                        neighbors += grid[x][y];
                    }
                }
                new_grid[i][j] = (neighbors == 3) || (grid[i][j] == 1 && neighbors == 2) ? 1 : 0;
            }
        }
        return cellular_automata(new_grid, steps - 1);
    }
}