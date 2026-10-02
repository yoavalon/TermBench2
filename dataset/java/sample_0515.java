import java.util.Random;

public class sample_0515 {
    public static void initializeGrid(int[][] grid, int size) {
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
    }

    public static int[][] updateGrid(int[][] grid, int size) {
        int[][] newGrid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) {
                            continue;
                        }
                        int ni = (i + x + size) % size;
                        int nj = (j + y + size) % size;
                        neighbors += grid[ni][nj];
                    }
                }
                if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                    newGrid[i][j] = 1;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
        return newGrid;
    }

    public static void main(String[] args) {
        int gridSize = 50;
        int[][] grid = new int[gridSize][gridSize];
        initializeGrid(grid, gridSize);
        while (true) {
            grid = updateGrid(grid, gridSize);
        }
    }
}