import java.util.Arrays;

public class sample_1038 {
    static int[][] update_grid(int[][] grid, int width, int height) {
        int[][] new_grid = new int[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int neighbors = 0;
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        int nx = (x + i + width) % width;
                        int ny = (y + j + height) % height;
                        neighbors += grid[ny][nx];
                    }
                }
                new_grid[y][x] = (2 < neighbors && neighbors < 4) ? 1 : 0;
            }
        }
        return new_grid;
    }

    static void simulate(int[][] grid, int width, int height) {
        print_grid(grid, width, height);
        simulate(update_grid(grid, width, height), width, height);
    }

    static void print_grid(int[][] grid, int width, int height) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                System.out.print(grid[y][x] == 1 ? "#" : " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int width = 50, height = 50;
        int[][] grid = new int[height][width];
        grid[25][25] = 1;
        simulate(grid, width, height);
    }
}