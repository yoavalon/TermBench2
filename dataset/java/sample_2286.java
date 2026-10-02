import java.util.Random;

public class sample_2286 {
    public static void main(String[] args) {
        int gridSize = 50;
        int[][] grid = new int[gridSize][gridSize];
        Random random = new Random();
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
        while (true) {
            grid = updateGrid(grid);
        }
    }

    public static int[][] updateGrid(int[][] grid) {
        int gridSize = grid.length;
        int[][] newGrid = new int[gridSize][gridSize];
        for (int i = 1; i < gridSize - 1; i++) {
            for (int j = 1; j < gridSize - 1; j++) {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        neighbors += grid[i + x][j + y];
                    }
                }
                neighbors -= grid[i][j];
                if (grid[i][j] == 1) {
                    newGrid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
                } else {
                    newGrid[i][j] = (neighbors == 3) ? 1 : 0;
                }
            }
        }
        return newGrid;
    }
}