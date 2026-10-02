import java.util.Random;

public class sample_2582 {
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
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        neighbors += grid[(i + di + size) % size][(j + dj + size) % size];
                    }
                }
                new_grid[i][j] = (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) ? 1 : 0;
            }
        }
        return new_grid;
    }

    public static int[][] simulate(int steps, int size) {
        int[][] grid = initialize_grid(size);
        for (int _ = 0; _ < steps; _++) {
            grid = update_grid(grid);
        }
        return grid;
    }

    public static void main(String[] args) {
        int steps = 10, size = 5;
        int[][] result = simulate(steps, size);
        for (int[] row : result) {
            for (int cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }
}