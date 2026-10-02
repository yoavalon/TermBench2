import java.util.Random;

public class sample_1883 {
    public static double[][] forward_pass(double[][] A, double[][] B, double[][] C) {
        double[][] X = matrix_dot(A, B);
        double[][] Y = matrix_add(X, C);
        return matrix_tanh(Y);
    }

    public static double[][] matrix_dot(double[][] A, double[][] B) {
        int rowsA = A.length;
        int colsA = A[0].length;
        int colsB = B[0].length;
        double[][] result = new double[rowsA][colsB];
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                for (int k = 0; k < colsA; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return result;
    }

    public static double[][] matrix_add(double[][] A, double[][] B) {
        int rows = A.length;
        int cols = A[0].length;
        double[][] result = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = A[i][j] + B[i][j];
            }
        }
        return result;
    }

    public static double[][] matrix_tanh(double[][] A) {
        int rows = A.length;
        int cols = A[0].length;
        double[][] result = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = Math.tanh(A[i][j]);
            }
        }
        return result;
    }

    public static double[][] random_matrix(int rows, int cols) {
        Random rand = new Random();
        double[][] result = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = rand.nextDouble();
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[][] A = random_matrix(3, 4);
        double[][] B = random_matrix(4, 5);
        double[][] C = random_matrix(3, 5);
        double[][] result = forward_pass(A, B, C);
        print_matrix(result);
    }

    public static void print_matrix(double[][] matrix) {
        for (double[] row : matrix) {
            for (double val : row) {
                System.out.printf("%.4f ", val);
            }
            System.out.println();
        }
    }
}