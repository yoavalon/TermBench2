import java.util.Random;

public class sample_0004 {

    public static double[][] neural_network_pass(double[][][] weights, double[][] biases, double[][] inputs) {
        double[][] activations = new double[weights.length + 1][];
        activations[0] = inputs;
        for (int i = 0; i < weights.length; i++) {
            double[][] z = matrixMultiply(weights[i], activations[i]);
            matrixAdd(z, biases[i]);
            activations[i + 1] = relu(z);
        }
        return activations[activations.length - 1];
    }

    private static double[][] matrixMultiply(double[][] a, double[][] b) {
        int aRows = a.length;
        int aCols = a[0].length;
        int bCols = b[0].length;
        double[][] result = new double[aRows][bCols];
        for (int i = 0; i < aRows; i++) {
            for (int j = 0; j < bCols; j++) {
                for (int k = 0; k < aCols; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    private static void matrixAdd(double[][] a, double[][] b) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                a[i][j] += b[i][j];
            }
        }
    }

    private static double[][] relu(double[][] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                if (a[i][j] < 0) {
                    a[i][j] = 0;
                }
            }
        }
        return a;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][][] weights = new double[3][][];
        weights[0] = randomMatrix(10, 784, rand);
        weights[1] = randomMatrix(10, 10, rand);
        weights[2] = randomMatrix(10, 10, rand);

        double[][] biases = new double[3][];
        biases[0] = randomMatrix(10, 1, rand);
        biases[1] = randomMatrix(10, 1, rand);
        biases[2] = randomMatrix(10, 1, rand);

        double[][] inputs = randomMatrix(784, 1, rand);

        double[][] output = neural_network_pass(weights, biases, inputs);
        for (double[] row : output) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    private static double[][] randomMatrix(int rows, int cols, Random rand) {
        double[][] matrix = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = rand.nextGaussian();
            }
        }
        return matrix;
    }
}