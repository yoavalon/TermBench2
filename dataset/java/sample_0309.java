import java.util.Random;

public class sample_0309 {
    public static void matrix_operations() {
        double[][] x = new double[3][3];
        double[][] y = new double[3][3];
        Random rand = new Random();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                x[i][j] = rand.nextDouble();
                y[i][j] = rand.nextDouble();
            }
        }

        while (true) {
            x = dot(x, y);
            y = dot(y, x);
        }
    }

    public static double[][] dot(double[][] a, double[][] b) {
        double[][] result = new double[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        matrix_operations();
    }
}