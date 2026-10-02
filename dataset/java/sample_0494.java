import java.util.Random;

public class sample_0494 {
    public static void main(String[] args) {
        int gridSize = 100;
        int[][] grid = initializeGrid(gridSize);
        while (true) {
            grid = updateGrid(grid);
            printGrid(grid);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static int[][] initializeGrid(int size) {
        int[][] grid = new int[size][size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = rand.nextInt(2);
            }
        }
        return grid;
    }

    public static int[][] updateGrid(int[][] grid) {
        int[][] newGrid = new int[grid.length][grid[0].length];
        for (int i = 1; i < grid.length - 1; i++) {
            for (int j = 1; j < grid[0].length - 1; j++) {
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
        int sum = 0;
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = col - 1; j <= col + 1; j++) {
                if (i == row && j == col) continue;
                sum += grid[i][j];
            }
        }
        return sum;
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