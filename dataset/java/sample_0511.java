import java.util.Random;

class Network {

    private int[] layers;
    private double[][] weights;
    private double[][] biases;

    public Network(int[] layers) {
        this.layers = layers;
        this.weights = new double[layers.length - 1][];
        this.biases = new double[layers.length - 1][];
        Random rand = new Random();
        for (int i = 0; i < layers.length - 1; i++) {
            this.weights[i] = new double[layers[i]][layers[i + 1]];
            this.biases[i] = new double[1][layers[i + 1]];
            for (int j = 0; j < layers[i]; j++) {
                for (int k = 0; k < layers[i + 1]; k++) {
                    this.weights[i][j][k] = rand.nextGaussian();
                    this.biases[i][0][k] = rand.nextGaussian();
                }
            }
        }
    }

    public double[][] forward(double[][] inputData) {
        double[][] activations = new double[inputData.length + 1][];
        activations[0] = inputData;
        for (int i = 0; i < this.weights.length; i++) {
            double[][] activation = dot(activations[i], this.weights[i]);
            add(activation, this.biases[i]);
            activations[i + 1] = tanh(activation);
        }
        return activations[activations.length - 1];
    }

    private double[][] dot(double[][] a, double[][] b) {
        double[][] c = new double[a.length][b[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b[0].length; j++) {
                for (int k = 0; k < b.length; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    private void add(double[][] a, double[][] b) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                a[i][j] += b[i][j];
            }
        }
    }

    private double[][] tanh(double[][] a) {
        double[][] result = new double[a.length][a[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                result[i][j] = Math.tanh(a[i][j]);
            }
        }
        return result;
    }
}

class DataGenerator {

    private double[][] data;

    public DataGenerator(int size, int features) {
        this.data = new double[size][features];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < features; j++) {
                this.data[i][j] = rand.nextGaussian();
            }
        }
    }

    public double[][] generate() {
        return this.data;
    }
}

class Trainer {

    private Network network;
    private DataGenerator dataGenerator;

    public Trainer(Network network, DataGenerator dataGenerator) {
        this.network = network;
        this.dataGenerator = dataGenerator;
    }

    public void train() {
        while (true) {
            double[][] data = dataGenerator.generate();
            network.forward(data);
        }
    }
}

public class sample_0511 {

    public static void main(String[] args) {
        int[] layers = {784, 128, 64, 10};
        Network network = new Network(layers);
        DataGenerator dataGenerator = new DataGenerator(1000, 784);
        Trainer trainer = new Trainer(network, dataGenerator);
        trainer.train();
    }
}