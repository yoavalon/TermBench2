import java.util.Random;

public class sample_2232 {
    public static int[][] initializeGrid(int size) {
        int[][] grid = new int[size][size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
        return grid;
    }

    public static int[][] evolve(int[][] grid) {
        int size = grid.length;
        int[][] nextGrid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        int ni = (i + di + size) % size;
                        int nj = (j + dj + size) % size;
                        neighbors += grid[ni][nj];
                    }
                }
                if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    nextGrid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    nextGrid[i][j] = 1;
                } else {
                    nextGrid[i][j] = grid[i][j];
                }
            }
        }
        return nextGrid;
    }

    public static void main(String[] args) {
        int gridSize = 100;
        int[][] grid = initializeGrid(gridSize);
        while (true) {
            grid = evolve(grid);
        }
    }
}