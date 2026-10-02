import java.util.Arrays;
import java.util.Random;

class MatrixOp {
    private double[][] data;

    public MatrixOp(double[][] data) {
        this.data = data;
    }

    public MatrixOp multiply(MatrixOp other) {
        double[][] result = new double[this.data.length][other.data[0].length];
        for (int i = 0; i < this.data.length; i++) {
            for (int j = 0; j < other.data[0].length; j++) {
                for (int k = 0; k < other.data.length; k++) {
                    result[i][j] += this.data[i][k] * other.data[k][j];
                }
            }
        }
        return new MatrixOp(result);
    }

    public MatrixOp add(MatrixOp other) {
        double[][] result = new double[this.data.length][this.data[0].length];
        for (int i = 0; i < this.data.length; i++) {
            for (int j = 0; j < this.data[0].length; j++) {
                result[i][j] = this.data[i][j] + other.data[i][j];
            }
        }
        return new MatrixOp(result);
    }

    public MatrixOp sigmoid() {
        double[][] result = new double[this.data.length][this.data[0].length];
        for (int i = 0; i < this.data.length; i++) {
            for (int j = 0; j < this.data[0].length; j++) {
                result[i][j] = 1 / (1 + Math.exp(-this.data[i][j]));
            }
        }
        return new MatrixOp(result);
    }

    public MatrixOp relu() {
        double[][] result = new double[this.data.length][this.data[0].length];
        for (int i = 0; i < this.data.length; i++) {
            for (int j = 0; j < this.data[0].length; j++) {
                result[i][j] = Math.max(0, this.data[i][j]);
            }
        }
        return new MatrixOp(result);
    }
}

class NeuralNetwork {
    private Layer[] layers;

    public NeuralNetwork(Layer[] layers) {
        this.layers = layers;
    }

    public MatrixOp forward_pass(MatrixOp input_data) {
        MatrixOp result = input_data;
        for (Layer layer : layers) {
            result = layer.forward(result);
        }
        return result;
    }
}

class Layer {
    private MatrixOp weights;
    private Activation activation;

    public Layer(double[][] weights, Activation activation) {
        this.weights = new MatrixOp(weights);
        this.activation = activation;
    }

    public MatrixOp forward(MatrixOp input_data) {
        MatrixOp weighted_input = weights.multiply(input_data);
        MatrixOp activated_output = activation.apply(weighted_input);
        return activated_output;
    }
}

interface Activation {
    MatrixOp apply(MatrixOp input);
}

class Sigmoid implements Activation {
    public MatrixOp apply(MatrixOp input) {
        return input.sigmoid();
    }
}

class ReLU implements Activation {
    public MatrixOp apply(MatrixOp input) {
        return input.relu();
    }
}

public class sample_0840 {
    public static void main(String[] args) {
        Random random = new Random(0);
        double[][] input_data = new double[3][1];
        for (int i = 0; i < input_data.length; i++) {
            input_data[i][0] = random.nextDouble();
        }
        double[][] weights1 = new double[2][3];
        for (int i = 0; i < weights1.length; i++) {
            for (int j = 0; j < weights1[0].length; j++) {
                weights1[i][j] = random.nextDouble();
            }
        }
        double[][] weights2 = new double[1][2];
        for (int i = 0; i < weights2.length; i++) {
            for (int j = 0; j < weights2[0].length; j++) {
                weights2[i][j] = random.nextDouble();
            }
        }
        Layer layer1 = new Layer(weights1, new Sigmoid());
        Layer layer2 = new Layer(weights2, new ReLU());
        NeuralNetwork network = new NeuralNetwork(new Layer[]{layer1, layer2});
        MatrixOp output = network.forward_pass(new MatrixOp(input_data));
        System.out.println(Arrays.deepToString(output.data));
    }
}