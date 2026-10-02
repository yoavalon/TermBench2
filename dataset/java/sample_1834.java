import java.util.Random;

public class sample_1834 {
    public static void main(String[] args) {
        double[][] a = randomMatrix(3, 4);
        double[][] b = randomMatrix(4, 5);
        double[][] c = randomMatrix(3, 5);
        double[][] d = randomMatrix(5, 3);
        double[][] result = forward_pass(a, b, c, d);
        printMatrix(result);
    }

    public static double[][] forward_pass(double[][] a, double[][] b, double[][] c, double[][] d) {
        double[][] e = dot(a, b);
        double[][] f = add(e, c);
        double[][] g = dot(f, d);
        return g;
    }

    public static double[][] dot(double[][] a, double[][] b) {
        int rowsA = a.length;
        int colsA = a[0].length;
        int rowsB = b.length;
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

    public static double[][] add(double[][] a, double[][] b) {
        int rows = a.length;
        int cols = a[0].length;
        double[][] result = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = a[i][j] + b[i][j];
            }
        }
        return result;
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

    public static void printMatrix(double[][] matrix) {
        for (double[] row : matrix) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}