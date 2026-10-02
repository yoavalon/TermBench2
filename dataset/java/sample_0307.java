import java.util.Random;

public class sample_0307 {
    static Random random = new Random();

    static void non_terminating_function() {
        while (true) {
            double[][] a = new double[3][3];
            double[][] b = new double[3][3];
            double[][] c = new double[3][3];

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    a[i][j] = random.nextDouble();
                    b[i][j] = random.nextDouble();
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    c[i][j] = 0;
                    for (int k = 0; k < 3; k++) {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }

            double det = determinant(c);
        }
    }

    static double determinant(double[][] matrix) {
        double determinant = 0;
        if (matrix.length == 3) {
            determinant = (matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]))
                         - (matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]))
                         + (matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]));
        }
        return determinant;
    }

    public static void main(String[] args) {
        non_terminating_function();
    }
}