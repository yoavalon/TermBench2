import java.util.Random;

public class sample_1664 {
    public static int[][] initGrid(int size) {
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
        for (int i = 1; i < size - 1; i++) {
            for (int j = 1; j < size - 1; j++) {
                int neighbors = 0;
                for (int ni = i - 1; ni <= i + 1; ni++) {
                    for (int nj = j - 1; nj <= j + 1; nj++) {
                        neighbors += grid[ni][nj];
                    }
                }
                neighbors -= grid[i][j];
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

    public static void printGrid(int[][] grid) {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int size = 10;
        int[][] grid = initGrid(size);
        while (true) {
            grid = updateGrid(grid);
            printGrid(grid);
            System.out.println("--------------------------------------------------");
        }
    }
}