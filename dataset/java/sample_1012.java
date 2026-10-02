import java.util.Arrays;

public class sample_1012 {
    public static int[][] updateGrid(int[][] grid) {
        int[][] newGrid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int liveNeighbors = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) continue;
                        int ni = i + x;
                        int nj = j + y;
                        if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[0].length) {
                            liveNeighbors += grid[ni][nj];
                        }
                    }
                }
                if (grid[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) {
                    newGrid[i][j] = 1;
                } else if (grid[i][j] == 0 && liveNeighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        return newGrid;
    }

    public static void simulate(int[][] grid) {
        display(grid);
        simulate(updateGrid(grid));
    }

    public static void display(int[][] grid) {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell == 1 ? "█" : " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] initialGrid = {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 0}
        };
        simulate(initialGrid);
    }
}