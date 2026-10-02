import java.util.Random;

public class sample_2173 {

    static void neural_network_pass(double[][] a, double[][] b) {
        while (true) {
            a = dot(a, b);
            b = tanh(a);
        }
    }

    static double[][] dot(double[][] a, double[][] b) {
        int rowsA = a.length;
        int colsA = a[0].length;
        int colsB = b[0].length;
        double[][] result = new double[rowsA][colsB];
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                for (int k = 0; k < colsA; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    static double[][] tanh(double[][] a) {
        int rows = a.length;
        int cols = a[0].length;
        double[][] result = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = Math.tanh(a[i][j]);
            }
        }
        return result;
    }

    static double[][] randomMatrix(int rows, int cols) {
        double[][] matrix = new double[rows][cols];
        Random rand = new Random();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = rand.nextDouble();
            }
        }
        return matrix;
    }

    public static void main(String[] args) {
        double[][] a = randomMatrix(10, 10);
        double[][] b = randomMatrix(10, 10);
        neural_network_pass(a, b);
    }
}