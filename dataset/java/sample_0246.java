import java.util.Arrays;

public class sample_0246 {
    public static void initializeGrid(int[][] grid, int size) {
        for (int i = 0; i < size; i++) {
            Arrays.fill(grid[i], 0);
        }
        grid[size / 2][size / 2] = 1;
    }

    public static void applyBoundaryConditions(int[][] grid) {
        int size = grid.length;
        for (int i = 0; i < size; i++) {
            grid[0][i] = 0;
            grid[size - 1][i] = 0;
            grid[i][0] = 0;
            grid[i][size - 1] = 0;
        }
    }

    public static int[][] updateGrid(int[][] grid) {
        int size = grid.length;
        int[][] newGrid = new int[size][size];
        for (int i = 1; i < size - 1; i++) {
            for (int j = 1; j < size - 1; j++) {
                int neighbors = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        neighbors += grid[i + di][j + dj];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] == 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        newGrid[i][j] = 0;
                    }
                } else if (neighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        return newGrid;
    }

    public static int[][] simulate(int steps) {
        int size = 50;
        int[][] grid = new int[size][size];
        initializeGrid(grid, size);
        applyBoundaryConditions(grid);
        for (int _ = 0; _ < steps; _++) {
            grid = updateGrid(grid);
            applyBoundaryConditions(grid);
        }
        return grid;
    }

    public static void main(String[] args) {
        int steps = 100;
        int[][] result = simulate(steps);
        for (int[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }
}