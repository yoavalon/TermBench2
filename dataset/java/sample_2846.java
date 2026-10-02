import java.util.Random;

public class sample_2846 {
    public static int[][] generateGrid(int size) {
        int[][] grid = new int[size][size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
        return grid;
    }

    public static int[][] updateGrid(int[][] grid) {
        int size = grid.length;
        int[][] newGrid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                    }
                }
                if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3) || (grid[i][j] == 0 && neighbors == 3)) {
                    newGrid[i][j] = 1;
                }
            }
        }
        return newGrid;
    }

    public static void main(String[] args) {
        int size = 10;
        int[][] grid = generateGrid(size);
        while (true) {
            grid = updateGrid(grid);
        }
    }
}