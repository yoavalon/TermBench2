import java.util.Random;

public class sample_2899 {
    public static void main(String[] args) {
        simulate();
    }

    public static int[][] updateGrid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] newGrid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int ni = Math.max(0, i - 1); ni < Math.min(rows, i + 2); ni++) {
                    for (int nj = Math.max(0, j - 1); nj < Math.min(cols, j + 2); nj++) {
                        neighbors += grid[ni][nj];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    newGrid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        return newGrid;
    }

    public static void simulate() {
        int[][] grid = new int[10][10];
        Random random = new Random();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
        while (true) {
            grid = updateGrid(grid);
            printGrid(grid);
            if (allCellsZero(grid)) {
                break;
            }
        }
    }

    public static void printGrid(int[][] grid) {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }

    public static boolean allCellsZero(int[][] grid) {
        for (int[] row : grid) {
            for (int cell : row) {
                if (cell != 0) {
                    return false;
                }
            }
        }
        return true;
    }
}