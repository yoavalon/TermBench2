import java.util.Random;

public class sample_1346 {

    public static int[][] initialize_grid(int size) {
        Random random = new Random();
        int[][] grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
        return grid;
    }

    public static int[][] update_grid(int[][] grid) {
        int size = grid.length;
        int[][] new_grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < size && y >= 0 && y < size && (x != i || y != j)) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (grid[i][j] == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = grid[i][j];
                }
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int size = 5;
        int[][] grid = initialize_grid(size);
        for (int i = 0; i < 10; i++) {
            grid = update_grid(grid);
        }
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }
}