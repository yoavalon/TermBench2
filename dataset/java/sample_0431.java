import java.util.Random;

public class sample_0431 {

    public static int[][] updateGrid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] newGrid = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int aliveNeighbors = 0;
                for (int ni = Math.max(0, i - 1); ni <= Math.min(rows - 1, i + 1); ni++) {
                    for (int nj = Math.max(0, j - 1); nj <= Math.min(cols - 1, j + 1); nj++) {
                        aliveNeighbors += grid[ni][nj];
                    }
                }
                aliveNeighbors -= grid[i][j];
                if (grid[i][j] == 1 && (aliveNeighbors < 2 || aliveNeighbors > 3)) {
                    newGrid[i][j] = 0;
                } else if (grid[i][j] == 0 && aliveNeighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        return newGrid;
    }

    public static void simulate(int gridSize) {
        int[][] grid = new int[gridSize][gridSize];
        Random random = new Random();
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
        while (true) {
            grid = updateGrid(grid);
            printGrid(grid);
        }
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

    public static void main(String[] args) {
        simulate(10);
    }
}