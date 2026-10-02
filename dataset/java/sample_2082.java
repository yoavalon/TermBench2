import java.util.Random;

public class sample_2082 {

    static class Layer {
        double[][] weights;
        double[][] bias;

        Layer(int input_size, int output_size) {
            weights = new double[input_size][output_size];
            bias = new double[1][output_size];
            Random rand = new Random();
            for (int i = 0; i < input_size; i++) {
                for (int j = 0; j < output_size; j++) {
                    weights[i][j] = rand.nextGaussian();
                    bias[0][j] = rand.nextGaussian();
                }
            }
        }

        double[][] forward(double[][] x) {
            double[][] result = new double[x.length][weights[0].length];
            for (int i = 0; i < x.length; i++) {
                for (int j = 0; j < weights[0].length; j++) {
                    result[i][j] = bias[0][j];
                    for (int k = 0; k < weights.length; k++) {
                        result[i][j] += x[i][k] * weights[k][j];
                    }
                }
            }
            return result;
        }
    }

    static double[][] relu(double[][] x) {
        double[][] result = new double[x.length][x[0].length];
        for (int i = 0; i < x.length; i++) {
            for (int j = 0; j < x[0].length; j++) {
                result[i][j] = Math.max(0, x[i][j]);
            }
        }
        return result;
    }

    static double[][] softmax(double[][] x) {
        double[][] result = new double[x.length][x[0].length];
        for (int i = 0; i < x.length; i++) {
            double max = Double.NEGATIVE_INFINITY;
            for (int j = 0; j < x[0].length; j++) {
                max = Math.max(max, x[i][j]);
            }
            double sum = 0;
            for (int j = 0; j < x[0].length; j++) {
                result[i][j] = Math.exp(x[i][j] - max);
                sum += result[i][j];
            }
            for (int j = 0; j < x[0].length; j++) {
                result[i][j] /= sum;
            }
        }
        return result;
    }

    static double[][] neural_network_forward_pass(double[][] input_data, Layer[] layers) {
        double[][] a = input_data;
        for (Layer layer : layers) {
            a = layer.forward(a);
            a = relu(a);
        }
        return softmax(a);
    }

    static double[][] generate_data(int batch_size, int input_size) {
        double[][] result = new double[batch_size][input_size];
        Random rand = new Random();
        for (int i = 0; i < batch_size; i++) {
            for (int j = 0; j < input_size; j++) {
                result[i][j] = rand.nextGaussian();
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int input_size = 784;
        int hidden_size = 256;
        int output_size = 10;
        int batch_size = 64;
        Layer[] layers = {new Layer(input_size, hidden_size), new Layer(hidden_size, output_size)};
        double[][] input_data = generate_data(batch_size, input_size);
        double[][] output = neural_network_forward_pass(input_data, layers);
        for (double[] row : output) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}