import java.util.Random;

class Activation {

    double sigmoid(double x) {
        return 1 / (1 + Math.exp(-x));
    }

    double relu(double x) {
        return Math.max(0, x);
    }
}

class Layer {

    double[][] weights;
    double[] bias;
    Activation activation;

    Layer(double[][] weights, double[] bias, Activation activation) {
        this.weights = weights;
        this.bias = bias;
        this.activation = activation;
    }

    double[] forward(double[] input_data) {
        double[] z = new double[bias.length];
        for (int i = 0; i < bias.length; i++) {
            for (int j = 0; j < input_data.length; j++) {
                z[i] += input_data[j] * weights[j][i];
            }
            z[i] += bias[i];
        }
        for (int i = 0; i < z.length; i++) {
            z[i] = activation.sigmoid(z[i]);
        }
        return z;
    }
}

class NeuralNetwork {

    Layer[] layers;

    NeuralNetwork(Layer[] layers) {
        this.layers = layers;
    }

    double[] predict(double[][] input_data) {
        double[] output_data = input_data[0];
        for (Layer layer : layers) {
            output_data = layer.forward(output_data);
        }
        return output_data;
    }
}

public class sample_0827 {

    static double[][] initialize_network(int[] layer_sizes, String activation_type) {
        Activation activation = new Activation();
        Layer[] layers = new Layer[layer_sizes.length - 1];
        Random random = new Random();
        for (int i = 0; i < layer_sizes.length - 1; i++) {
            double[][] weights = new double[layer_sizes[i]][layer_sizes[i + 1]];
            for (int j = 0; j < layer_sizes[i]; j++) {
                for (int k = 0; k < layer_sizes[i + 1]; k++) {
                    weights[j][k] = random.nextGaussian();
                }
            }
            double[] bias = new double[layer_sizes[i + 1]];
            for (int j = 0; j < layer_sizes[i + 1]; j++) {
                bias[j] = random.nextGaussian();
            }
            if (activation_type.equals("sigmoid")) {
                layers[i] = new Layer(weights, bias, activation);
            } else if (activation_type.equals("relu")) {
                layers[i] = new Layer(weights, bias, activation);
            }
        }
        return layers;
    }

    public static void main(String[] args) {
        double[][] input_data = {
            {0, 0},
            {0, 1},
            {1, 0},
            {1, 1}
        };
        double[][] expected_output = {
            {0},
            {1},
            {1},
            {0}
        };
        Layer[] network = initialize_network(new int[]{2, 4, 1}, "sigmoid");
        double[] output = new NeuralNetwork(network).predict(input_data);
        for (double value : output) {
            System.out.println(value);
        }
    }
}