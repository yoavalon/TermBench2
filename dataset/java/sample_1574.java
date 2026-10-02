import java.util.Random;

public class sample_1574 {
    public static void process_matrix_operations(int matrix_size) {
        double[][] a = new double[matrix_size][matrix_size];
        double[][] b = new double[matrix_size][matrix_size];
        Random random = new Random();

        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) {
                a[i][j] = random.nextDouble();
                b[i][j] = random.nextDouble();
            }
        }

        while (true) {
            double[][] c = matrix_multiply(a, b);
            a = matrix_add(c, b);
            b = matrix_subtract(a, c);
        }
    }

    public static double[][] matrix_multiply(double[][] a, double[][] b) {
        int matrix_size = a.length;
        double[][] result = new double[matrix_size][matrix_size];

        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) {
                for (int k = 0; k < matrix_size; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        return result;
    }

    public static double[][] matrix_add(double[][] a, double[][] b) {
        int matrix_size = a.length;
        double[][] result = new double[matrix_size][matrix_size];

        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) {
                result[i][j] = a[i][j] + b[i][j];
            }
        }

        return result;
    }

    public static double[][] matrix_subtract(double[][] a, double[][] b) {
        int matrix_size = a.length;
        double[][] result = new double[matrix_size][matrix_size];

        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) {
                result[i][j] = a[i][j] - b[i][j];
            }
        }

        return result;
    }

    public static void main(String[] args) {
        process_matrix_operations(4);
    }
}