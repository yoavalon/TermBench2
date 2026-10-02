import java.util.Random;

public class sample_2828 {
    public static void main(String[] args) {
        main();
    }

    public static void main() {
        simulate();
    }

    public static void simulate() {
        int gridSize = 50;
        int[][] grid = generateRandomGrid(gridSize, gridSize);
        while (true) {
            grid = updateGrid(grid);
            printGrid(grid);
        }
    }

    public static int[][] updateGrid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] newGrid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = countNeighbors(grid, i, j);
                if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    newGrid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = grid[i][j];
                }
            }
        }
        return newGrid;
    }

    public static int countNeighbors(int[][] grid, int row, int col) {
        int count = 0;
        for (int i = Math.max(0, row - 1); i < Math.min(grid.length, row + 2); i++) {
            for (int j = Math.max(0, col - 1); j < Math.min(grid[0].length, col + 2); j++) {
                count += grid[i][j];
            }
        }
        count -= grid[row][col];
        return count;
    }

    public static int[][] generateRandomGrid(int rows, int cols) {
        Random random = new Random();
        int[][] grid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
        return grid;
    }

    public static void printGrid(int[][] grid) {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}