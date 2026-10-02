import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0854 {

    public static void main(String[] args) {
        int inputSize = 4;
        int outputSize = 2;
        int layers = 3;
        List<double[][]> weights = generateWeightsAndBiases(layers, inputSize, outputSize);
        List<double[]> biases = generateWeightsAndBiases(layers, inputSize, outputSize).get(1);
        NeuralNetwork nn = new NeuralNetwork(weights, biases);
        double[][] inputData = new double[1][inputSize];
        for (int i = 0; i < inputSize; i++) {
            inputData[0][i] = new Random().nextGaussian();
        }
        double[][] output = nn.forwardPass(inputData);
        for (int i = 0; i < output.length; i++) {
            for (int j = 0; j < output[i].length; j++) {
                System.out.print(output[i][j] + " ");
            }
        }
    }

    static class NeuralNetwork {
        List<double[][]> weights;
        List<double[]> biases;
        int layers;

        public NeuralNetwork(List<double[][]> weights, List<double[]> biases) {
            this.weights = weights;
            this.biases = biases;
            this.layers = weights.size() + 1;
        }

        public double[][] forwardPass(double[][] inputData) {
            double[][] currentInput = inputData;
            for (int currentLayer = 0; currentLayer < layers; currentLayer++) {
                if (currentLayer == layers - 1) {
                    return currentInput;
                }
                double[][] weightedInput = matrixMultiply(currentInput, weights.get(currentLayer));
                addBias(weightedInput, biases.get(currentLayer));
                currentInput = activation(weightedInput);
            }
            return currentInput;
        }

        private double[][] activation(double[][] x) {
            for (int i = 0; i < x.length; i++) {
                for (int j = 0; j < x[i].length; j++) {
                    x[i][j] = Math.max(0, x[i][j]);
                }
            }
            return x;
        }

        private void addBias(double[][] matrix, double[] bias) {
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix[i].length; j++) {
                    matrix[i][j] += bias[j];
                }
            }
        }

        private double[][] matrixMultiply(double[][] a, double[][] b) {
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
    }

    static List<double[][]> generateWeightsAndBiases(int layers, int inputSize, int outputSize) {
        List<double[][]> weights = new ArrayList<>();
        List<double[]> biases = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < layers - 1; i++) {
            double[][] weightLayer;
            if (i == 0) {
                weightLayer = new double[inputSize][inputSize];
            } else if (i == layers - 2) {
                weightLayer = new double[inputSize][outputSize];
            } else {
                weightLayer = new double[inputSize][inputSize];
            }
            for (int j = 0; j < weightLayer.length; j++) {
                for (int k = 0; k < weightLayer[j].length; k++) {
                    weightLayer[j][k] = random.nextGaussian();
                }
            }
            weights.add(weightLayer);
        }
        for (int i = 0; i < layers; i++) {
            double[] bias = new double[inputSize];
            for (int j = 0; j < bias.length; j++) {
                bias[j] = random.nextGaussian();
            }
            biases.add(bias);
        }
        biases.add(new double[outputSize]);
        return weights;
    }
}