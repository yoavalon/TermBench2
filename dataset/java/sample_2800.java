import java.util.Random;

public class sample_2800 {

    public static void matrix_forward_pass() {
        Random random = new Random();
        double[][] a = new double[3][3];
        double[][] b = new double[3][3];
        double[][] c = new double[3][3];
        double[][] d = new double[3][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = random.nextDouble();
                b[i][j] = random.nextDouble();
            }
        }

        while (true) {
            matrix_multiply(a, b, c);
            matrix_tanh(c, d);
            a = d;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    b[i][j] = random.nextDouble();
                }
            }
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

    public static void matrix_tanh(double[][] a, double[][] b) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                b[i][j] = Math.tanh(a[i][j]);
            }
        }
    }

    public static void main(String[] args) {
        matrix_forward_pass();
    }
}