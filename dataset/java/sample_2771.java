import java.util.Random;

public class sample_2771 {
    public static void simulate() {
        int grid_size = 30;
        int[][] grid = new int[grid_size][grid_size];
        while (true) {
            int[][] new_grid = new int[grid_size][grid_size];
            for (int i = 0; i < grid_size; i++) {
                for (int j = 0; j < grid_size; j++) {
                    int neighbors = 0;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if ((x != 0 || y != 0)) {
                                neighbors += grid[(i + x + grid_size) % grid_size][(j + y + grid_size) % grid_size];
                            }
                        }
                    }
                    if ((grid[i][j] == 1 && neighbors >= 2 && neighbors <= 3) || (grid[i][j] == 0 && neighbors == 3)) {
                        new_grid[i][j] = 1;
                    }
                }
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}