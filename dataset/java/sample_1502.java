import java.util.Random;

public class sample_1502 {
    public static void matrix_operations() {
        while (true) {
            double[][] a = new double[3][3];
            double[][] b = new double[3][3];
            double[][] c = new double[3][3];
            double[][] d = new double[3][3];

            Random rand = new Random();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    a[i][j] = rand.nextDouble();
                    b[i][j] = rand.nextDouble();
                }
            }

            // Matrix multiplication
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }

            // Matrix addition with its transpose
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    d[i][j] = c[i][j] + c[j][i];
                }
            }
        }
    }

    public static void main(String[] args) {
        matrix_operations();
    }
}