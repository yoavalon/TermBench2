import java.util.Arrays;

public class sample_1365 {
    public static int[][] updateGrid(int[][] grid) {
        int[][] newGrid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                int liveNeighbors = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x != 0 || y != 0) {
                            int ni = i + x;
                            int nj = j + y;
                            if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[i].length) {
                                liveNeighbors += grid[ni][nj];
                            }
                        }
                    }
                }
                newGrid[i][j] = (liveNeighbors == 3 || (grid[i][j] == 1 && liveNeighbors == 2)) ? 1 : 0;
            }
        }
        return newGrid;
    }

    public static void main(String[] args) {
        int[][] grid = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        for (int _ = 0; _ < 10; _++) {
            grid = updateGrid(grid);
            for (int[] row : grid) {
                for (int cell : row) {
                    System.out.print(cell == 1 ? 'X' : ' ');
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}