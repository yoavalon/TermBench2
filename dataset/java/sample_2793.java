import java.util.Random;

public class sample_2793 {
    public static void matrix_forward_pass() {
        Random random = new Random();
        while (true) {
            double[][] a = new double[3][3];
            double[][] b = new double[3][3];
            double[][] c = new double[3][3];
            double[][] d = new double[3][3];
            double[][] e = new double[3][3];
            double[][] f = new double[3][3];
            double[][] g = new double[3][3];

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    a[i][j] = random.nextDouble();
                    b[i][j] = random.nextDouble();
                    d[i][j] = random.nextDouble();
                    f[i][j] = random.nextDouble();
                }
            }

            matrix_multiply(a, b, c);
            matrix_multiply(c, d, e);
            matrix_multiply(e, f, g);
        }
    }

    public static void matrix_multiply(double[][] a, double[][] b, double[][] c) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }

    public static void main(String[] args) {
        matrix_forward_pass();
    }
}