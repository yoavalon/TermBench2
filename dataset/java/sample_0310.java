import java.util.Random;

public class sample_0310 {
    public static void simulate() {
        int[][] grid = new int[10][10];
        Random random = new Random();
        while (true) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    int sum = 0;
                    if (i > 0) sum += grid[i - 1][j];
                    if (i < 9) sum += grid[i + 1][j];
                    if (j > 0) sum += grid[i][j - 1];
                    if (j < 9) sum += grid[i][j + 1];
                    if (sum > 4) {
                        grid[i][j] = 1;
                    } else {
                        grid[i][j] = random.nextInt(2);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}