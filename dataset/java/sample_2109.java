import java.util.Random;

public class sample_2109 {
    public static void simulate() {
        double[][] grid = new double[100][100];
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                grid[i][j] = random.nextDouble();
            }
        }
        while (true) {
            double[][] new_grid = new double[100][100];
            for (int i = 1; i < 99; i++) {
                for (int j = 1; j < 99; j++) {
                    new_grid[i][j] = 0.25 * (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]);
                }
            }
            grid = new_grid;
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}