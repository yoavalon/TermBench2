import java.util.Random;

public class sample_0830 {

    public static double[][] matrixMultiply(double[][] a, double[][] b) {
        double[][] result = new double[a.length][b[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b[0].length; j++) {
                for (int k = 0; k < a[0].length; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    public static double[][] activate(double[][] x) {
        for (int i = 0; i < x.length; i++) {
            for (int j = 0; j < x[0].length; j++) {
                x[i][j] = Math.max(0, x[i][j]);
            }
        }
        return x;
    }

    public static double[][] forwardPass(double[][] weights, double[][] biases, double[][] input_data, int depth) {
        if (depth == 0) {
            return input_data;
        }
        double[][] layer_output = matrixMultiply(input_data, weights);
        for (int i = 0; i < layer_output.length; i++) {
            for (int j = 0; j < layer_output[0].length; j++) {
                layer_output[i][j] += biases[i][j];
            }
        }
        layer_output = activate(layer_output);
        return forwardPass(weights, biases, layer_output, depth - 1);
    }

    static class NeuralNetwork {
        double[][][] weights;
        double[][] biases;
        Random random = new Random();

        public NeuralNetwork(int[] layers, int input_size) {
            weights = new double[layers.length][];
            biases = new double[layers.length][];
            weights[0] = new double[input_size][layers[0]];
            biases[0] = new double[layers[0]];
            for (int i = 0; i < input_size; i++) {
                for (int j = 0; j < layers[0]; j++) {
                    weights[0][i][j] = random.nextGaussian();
                    biases[0][j] = random.nextGaussian();
                }
            }
            for (int i = 1; i < layers.length; i++) {
                weights[i] = new double[layers[i - 1]][layers[i]];
                biases[i] = new double[layers[i]];
                for (int j = 0; j < layers[i - 1]; j++) {
                    for (int k = 0; k < layers[i]; k++) {
                        weights[i][j][k] = random.nextGaussian();
                        biases[i][k] = random.nextGaussian();
                    }
                }
            }
        }

        public double[][] predict(double[][] input_data, int depth) {
            return forwardPass(weights, biases, input_data, depth);
        }
    }

    public static void main(String[] args) {
        double[][] input_data = new double[1][10];
        for (int i = 0; i < input_data[0].length; i++) {
            input_data[0][i] = new Random().nextGaussian();
        }
        NeuralNetwork network = new NeuralNetwork(new int[]{20, 15, 5}, 10);
        double[][] output = network.predict(input_data, 3);
        for (double[] row : output) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}