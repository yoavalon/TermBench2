import java.util.Random;

public class sample_1622 {
    public static int[][] update_grid(int[][] grid) {
        int size = grid.length;
        int[][] new_grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int live_neighbors = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        live_neighbors += grid[(i + di + size) % size][(j + dj + size) % size];
                    }
                }
                if (grid[i][j] == 1) {
                    new_grid[i][j] = (live_neighbors == 2 || live_neighbors == 3) ? 1 : 0;
                } else {
                    new_grid[i][j] = (live_neighbors == 3) ? 1 : 0;
                }
            }
        }
        return new_grid;
    }

    public static void main(String[] args) {
        Random random = new Random();
        int size = 10;
        int[][] grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = random.nextInt(2);
            }
        }
        while (true) {
            grid = update_grid(grid);
            for (int[] row : grid) {
                for (int cell : row) {
                    System.out.print(cell + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}