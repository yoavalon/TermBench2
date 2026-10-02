import java.util.Random;

public class sample_2552 {
    public static double[][] matrix_multiply(double[][] a, double[][] b) {
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

    public static double[][] forward_pass(double[][][] weights, double[][] inputs, int layers) {
        double[][] output = inputs;
        for (int i = 0; i < layers; i++) {
            output = matrix_multiply(weights[i], output);
        }
        return output;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][][] weights = new double[5][10][10];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    weights[i][j][k] = rand.nextDouble();
                }
            }
        }

        double[][] inputs = new double[10][1];
        for (int i = 0; i < 10; i++) {
            inputs[i][0] = rand.nextDouble();
        }

        int layers = 5;
        double[][] result = forward_pass(weights, inputs, layers);

        for (double[] row : result) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}