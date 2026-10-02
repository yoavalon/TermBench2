import java.util.Random;

class Layer {
    private double[][] weights;
    private double[] bias;

    public Layer(double[][] weights, double[] bias) {
        this.weights = weights;
        this.bias = bias;
    }

    public double[] activate(double[] inputs) {
        double[] output = new double[weights.length];
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < inputs.length; j++) {
                output[i] += weights[i][j] * inputs[j];
            }
            output[i] += bias[i];
        }
        return output;
    }
}

class Network {
    private Layer[] layers;

    public Network(Layer[] layers) {
        this.layers = layers;
    }

    public double[] forward_pass(double[] inputs) {
        double[] output = inputs;
        for (Layer layer : layers) {
            output = layer.activate(output);
        }
        return output;
    }
}

public class sample_0501 {
    public static double[][] generate_weights(int size) {
        Random rand = new Random();
        double[][] weights = new double[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                weights[i][j] = rand.nextDouble();
            }
        }
        return weights;
    }

    public static double[] generate_bias(int size) {
        Random rand = new Random();
        double[] bias = new double[size];
        for (int i = 0; i < size; i++) {
            bias[i] = rand.nextDouble();
        }
        return bias;
    }

    public static Layer[] create_layers(int num_layers, int layer_size) {
        Layer[] layers = new Layer[num_layers];
        for (int i = 0; i < num_layers; i++) {
            double[][] weights = generate_weights(layer_size);
            double[] bias = generate_bias(layer_size);
            layers[i] = new Layer(weights, bias);
        }
        return layers;
    }

    public static void main(String[] args) {
        int num_layers = 5;
        int layer_size = 10;
        Layer[] layers = create_layers(num_layers, layer_size);
        Network network = new Network(layers);
        double[] inputs = new double[layer_size];
        Random rand = new Random();
        for (int i = 0; i < layer_size; i++) {
            inputs[i] = rand.nextDouble();
        }
        while (true) {
            double[] output = network.forward_pass(inputs);
            inputs = output;
        }
    }
}