import java.util.Random;

public class sample_0106 {
    public static void main(String[] args) {
        main();
    }

    public static double[][] initialize_weights(int input_size, int hidden_size, int output_size) {
        Random rand = new Random();
        double[][] W1 = new double[input_size][hidden_size];
        double[][] W2 = new double[hidden_size][output_size];
        for (int i = 0; i < input_size; i++) {
            for (int j = 0; j < hidden_size; j++) {
                W1[i][j] = rand.nextGaussian();
            }
        }
        for (int i = 0; i < hidden_size; i++) {
            for (int j = 0; j < output_size; j++) {
                W2[i][j] = rand.nextGaussian();
            }
        }
        return new double[][]{W1, W2};
    }

    public static double[][] forward_pass(double[][] X, double[][] W1, double[][] W2) {
        double[][] Z1 = matrixMultiply(X, W1);
        double[][] A1 = tanh(Z1);
        double[][] Z2 = matrixMultiply(A1, W2);
        double[][] A2 = sigmoid(Z2);
        return A2;
    }

    public static double[][] matrixMultiply(double[][] A, double[][] B) {
        int rowsA = A.length;
        int colsA = A[0].length;
        int colsB = B[0].length;
        double[][] C = new double[rowsA][colsB];
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                for (int k = 0; k < colsA; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }

    public static double[][] tanh(double[][] Z) {
        int rows = Z.length;
        int cols = Z[0].length;
        double[][] A = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                A[i][j] = Math.tanh(Z[i][j]);
            }
        }
        return A;
    }

    public static double[][] sigmoid(double[][] Z) {
        int rows = Z.length;
        int cols = Z[0].length;
        double[][] A = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                A[i][j] = 1 / (1 + Math.exp(-Z[i][j]));
            }
        }
        return A;
    }
}