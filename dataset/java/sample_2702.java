import java.util.Random;

public class sample_2702 {
    public static void vectorize_sequence() {
        Random random = new Random();
        while (true) {
            int[][] x = new int[10][10];
            int[][] y = new int[10][10];
            int[][] z = new int[10][10];

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    x[i][j] = random.nextInt(100);
                    y[i][j] = random.nextInt(100);
                }
            }

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 10; k++) {
                        z[i][j] += x[i][k] * y[k][j];
                    }
                }
            }

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    System.out.print(z[i][j] + " ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        vectorize_sequence();
    }
}