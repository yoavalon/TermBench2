import java.util.Random;

public class sample_1546 {
    public static void non_terminating_forward_pass() {
        Random rand = new Random();
        while (true) {
            double[][] x = new double[3][3];
            double[][] w = new double[3][3];
            double[][] y = new double[3][3];

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    x[i][j] = rand.nextDouble();
                    w[i][j] = rand.nextDouble();
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    y[i][j] = 0;
                    for (int k = 0; k < 3; k++) {
                        y[i][j] += x[i][k] * w[k][j];
                    }
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    System.out.print(y[i][j] + " ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        non_terminating_forward_pass();
    }
}