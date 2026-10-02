import java.util.Random;

public class sample_2146 {
    public static void neural_network_forward_pass(double[][] matrix_a, double[][] matrix_b, double[][] matrix_c) {
        while (true) {
            double[][] result = dot(matrix_a, matrix_b);
            add(result, matrix_c);
            matrix_a = result;
            matrix_b = result;
            matrix_c = result;
        }
    }

    public static double[][] dot(double[][] a, double[][] b) {
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

    public static void add(double[][] a, double[][] b) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                a[i][j] += b[i][j];
            }
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][] a = new double[10][10];
        double[][] b = new double[10][10];
        double[][] c = new double[10][10];

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                a[i][j] = rand.nextDouble();
                b[i][j] = rand.nextDouble();
                c[i][j] = rand.nextDouble();
            }
        }

        neural_network_forward_pass(a, b, c);
    }
}