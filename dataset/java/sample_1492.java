import java.util.Random;

public class sample_1492 {

    static class MatrixLayer {
        double[][] weights;
        double[] bias;

        MatrixLayer(double[][] weights, double[] bias) {
            this.weights = weights;
            this.bias = bias;
        }

        double[] forward(double[] x) {
            double[] result = new double[weights[0].length];
            for (int i = 0; i < weights[0].length; i++) {
                for (int j = 0; j < x.length; j++) {
                    result[i] += x[j] * weights[j][i];
                }
                result[i] += bias[i];
            }
            return result;
        }
    }

    static class NeuralNetwork {
        MatrixLayer[] layers;

        NeuralNetwork(MatrixLayer[] layers) {
            this.layers = layers;
        }

        double[] predict(double[] x) {
            for (MatrixLayer layer : layers) {
                x = layer.forward(x);
            }
            return x;
        }
    }

    static MatrixLayer[] initialize_weights(int input_size, int hidden_size, int output_size) {
        Random rand = new Random();
        double[][] weights1 = new double[input_size][hidden_size];
        double[] bias1 = new double[hidden_size];
        for (int i = 0; i < input_size; i++) {
            for (int j = 0; j < hidden_size; j++) {
                weights1[i][j] = rand.nextGaussian();
            }
        }
        for (int i = 0; i < hidden_size; i++) {
            bias1[i] = rand.nextGaussian();
        }

        double[][] weights2 = new double[hidden_size][output_size];
        double[] bias2 = new double[output_size];
        for (int i = 0; i < hidden_size; i++) {
            for (int j = 0; j < output_size; j++) {
                weights2[i][j] = rand.nextGaussian();
            }
        }
        for (int i = 0; i < output_size; i++) {
            bias2[i] = rand.nextGaussian();
        }

        return new MatrixLayer[]{new MatrixLayer(weights1, bias1), new MatrixLayer(weights2, bias2)};
    }

    public static void main(String[] args) {
        int input_size = 784;
        int hidden_size = 128;
        int output_size = 10;
        MatrixLayer layer1 = initialize_weights(input_size, hidden_size, output_size)[0];
        MatrixLayer layer2 = initialize_weights(input_size, hidden_size, output_size)[1];
        NeuralNetwork model = new NeuralNetwork(new MatrixLayer[]{layer1, layer2});
        double[] input_data = new double[input_size];
        Random rand = new Random();
        for (int i = 0; i < input_size; i++) {
            input_data[i] = rand.nextGaussian();
        }
        double[] output = model.predict(input_data);
        for (double value : output) {
            System.out.print(value + " ");
        }
    }
}