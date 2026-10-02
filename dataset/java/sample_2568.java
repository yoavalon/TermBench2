import java.util.Random;

public class sample_2568 {

    public static double[][] initialize_weights(int input_size, int hidden_size, int output_size) {
        double[][] w1 = new double[input_size][hidden_size];
        double[][] w2 = new double[hidden_size][output_size];
        Random rand = new Random();
        for (int i = 0; i < input_size; i++) {
            for (int j = 0; j < hidden_size; j++) {
                w1[i][j] = rand.nextGaussian();
            }
        }
        for (int i = 0; i < hidden_size; i++) {
            for (int j = 0; j < output_size; j++) {
                w2[i][j] = rand.nextGaussian();
            }
        }
        return new double[][][]{w1, w2};
    }

    public static double[][] forward_pass(double[][] x, double[][] w1, double[][] w2) {
        double[][] z1 = matrixMultiply(x, w1);
        double[][] a1 = new double[z1.length][z1[0].length];
        for (int i = 0; i < z1.length; i++) {
            for (int j = 0; j < z1[0].length; j++) {
                a1[i][j] = Math.tanh(z1[i][j]);
            }
        }
        double[][] z2 = matrixMultiply(a1, w2);
        return z2;
    }

    public static double[][] matrixMultiply(double[][] a, double[][] b) {
        double[][] result = new double[a.length][b[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b[0].length; j++) {
                for (int k = 0; k < b.length; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int input_size = 3;
        int hidden_size = 4;
        int output_size = 1;
        double[][][] weights = initialize_weights(input_size, hidden_size, output_size);
        double[][] w1 = weights[0];
        double[][] w2 = weights[1];
        double[][] x = new double[1][input_size];
        Random rand = new Random();
        for (int i = 0; i < input_size; i++) {
            x[0][i] = rand.nextGaussian();
        }
        double[][] output = forward_pass(x, w1, w2);
        for (double[] row : output) {
            for (double value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}