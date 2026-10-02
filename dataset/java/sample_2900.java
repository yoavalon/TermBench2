import java.util.Random;

public class sample_2900 {

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
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx != 0 || dy != 0) {
                            neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                        }
                    }
                }
                new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors == 2) ? grid[i][j] : 0;
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        int[][] grid = initialize_grid(10);
        while (true) {
            grid = update_grid(grid);
            for (int[] row : grid) {
                for (int cell : row) {
                    System.out.print((cell == 1) ? "O" : " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}