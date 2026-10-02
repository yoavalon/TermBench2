import java.util.Random;

public class sample_0663 {
    public static void main(String[] args) {
        double[][] A = randomMatrix(10, 5);
        double[][] W = randomMatrix(5, 5);
        double[] B = randomVector(5);
        int depth = 3;
        double[][] result = matrix_forward_pass(A, W, B, depth);
        printMatrix(result);
    }

    public static double[][] matrix_forward_pass(double[][] matrix, double[][] weights, double[] bias, int depth) {
        if (depth == 0) {
            return matrix;
        }
        return matrix_forward_pass(matrixDot(matrix, weights), weights, bias, depth - 1);
    }

    public static double[][] matrixDot(double[][] matrix, double[][] weights) {
        int rows = matrix.length;
        int cols = weights[0].length;
        int inner = matrix[0].length;
        double[][] result = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < inner; k++) {
                    result[i][j] += matrix[i][k] * weights[k][j];
                }
            }
        }
        return result;
    }

    public static double[][] addBias(double[][] matrix, double[] bias) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] += bias[j];
            }
        }
        return matrix;
    }

    public static double[][] randomMatrix(int rows, int cols) {
        Random rand = new Random();
        double[][] matrix = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = rand.nextDouble();
            }
        }
        return matrix;
    }

    public static double[] randomVector(int size) {
        Random rand = new Random();
        double[] vector = new double[size];
        for (int i = 0; i < size; i++) {
            vector[i] = rand.nextDouble();
        }
        return vector;
    }

    public static void printMatrix(double[][] matrix) {
        for (double[] row : matrix) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}