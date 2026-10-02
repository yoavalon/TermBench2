import java.util.Random;

public class sample_2166 {

    public static void neural_network_pass(double[][] A, double[][] B, double[][] C) {
        while (true) {
            double[][] X = matrixMultiply(A, B);
            double[][] Y = matrixMultiply(X, C);
            double[][] Z = matrixMultiply(Y, A);
            A = matrixMultiply(B, C);
            B = matrixMultiply(C, A);
            C = matrixMultiply(A, B);
        }
    }

    public static double[][] matrixMultiply(double[][] a, double[][] b) {
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

    public static void main(String[] args) {
        Random rand = new Random();
        double[][] A = new double[100][100];
        double[][] B = new double[100][100];
        double[][] C = new double[100][100];
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                A[i][j] = rand.nextDouble();
                B[i][j] = rand.nextDouble();
                C[i][j] = rand.nextDouble();
            }
        }
        neural_network_pass(A, B, C);
    }
}