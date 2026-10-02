import java.util.Random;

class NeuralNetwork {

    private double[][] weights;
    private double[] biases;

    public NeuralNetwork(double[][] weights, double[] biases) {
        this.weights = weights;
        this.biases = biases;
    }

    public double[] forward_pass(double[] data) {
        return _recurse_forward(data, 0);
    }

    private double[] _recurse_forward(double[] data, int index) {
        if (index >= weights.length) {
            return data;
        } else {
            double[] z = new double[weights[index].length];
            for (int i = 0; i < weights[index].length; i++) {
                for (int j = 0; j < data.length; j++) {
                    z[i] += weights[index][i][j] * data[j];
                }
                z[i] += biases[index];
            }
            double[] a = _activation(z);
            return _recurse_forward(a, index + 1);
        }
    }

    private double[] _activation(double[] z) {
        double[] a = new double[z.length];
        for (int i = 0; i < z.length; i++) {
            a[i] = Math.max(0, z[i]);
        }
        return a;
    }
}

class sample_0816 {

    public static double[][] generate_weights_and_biases(int[] layers, int input_size) {
        double[][] weights = new double[layers.length][];
        double[] biases = new double[layers.length];
        int previous_size = input_size;
        Random rand = new Random();
        for (int i = 0; i < layers.length; i++) {
            weights[i] = new double[layers[i]][previous_size];
            for (int j = 0; j < layers[i]; j++) {
                for (int k = 0; k < previous_size; k++) {
                    weights[i][j][k] = rand.nextGaussian();
                }
            }
            for (int j = 0; j < layers[i]; j++) {
                biases[i] = rand.nextGaussian();
            }
            previous_size = layers[i];
        }
        return weights;
    }

    public static void main(String[] args) {
        int input_size = 3;
        int[] layers = {4, 5, 2};
        double[][] weights = generate_weights_and_biases(layers, input_size);
        double[] biases = new double[layers.length];
        for (int i = 0; i < layers.length; i++) {
            biases[i] = 0;
        }
        NeuralNetwork nn = new NeuralNetwork(weights, biases);
        double[] data = new double[input_size];
        Random rand = new Random();
        for (int i = 0; i < input_size; i++) {
            data[i] = rand.nextGaussian();
        }
        double[] result = nn.forward_pass(data);
        for (double value : result) {
            System.out.println(value);
        }
    }
}