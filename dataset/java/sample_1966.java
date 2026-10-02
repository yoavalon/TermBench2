import java.util.Arrays;
import java.util.Random;

public class sample_1966 {

    public static double sigmoid(double x) {
        return 1 / (1 + Math.exp(-x));
    }

    public static double[] forward_pass(double[][][] weights, double[][] biases, double[] inputs) {
        for (int i = 0; i < weights.length; i++) {
            double[] weightedSum = new double[biases[i].length];
            for (int j = 0; j < biases[i].length; j++) {
                for (int k = 0; k < inputs.length; k++) {
                    weightedSum[j] += weights[i][j][k] * inputs[k];
                }
                weightedSum[j] += biases[i][j][0];
                weightedSum[j] = sigmoid(weightedSum[j]);
            }
            inputs = weightedSum;
        }
        return inputs;
    }

    public static void main(String[] args) {
        Random random = new Random(0);
        int layers = 3;
        int inputSize = 5;
        int outputSize = 1;
        int hiddenSize = 4;
        double[][][] weights = new double[layers][][];
        double[][] biases = new double[layers][];

        for (int i = 0; i < layers; i++) {
            if (i == 0) {
                weights[i] = new double[hiddenSize][inputSize];
                for (int j = 0; j < hiddenSize; j++) {
                    for (int k = 0; k < inputSize; k++) {
                        weights[i][j][k] = random.nextGaussian();
                    }
                }
                biases[i] = new double[hiddenSize][1];
                for (int j = 0; j < hiddenSize; j++) {
                    biases[i][j][0] = random.nextGaussian();
                }
            } else {
                weights[i] = new double[outputSize][hiddenSize];
                for (int j = 0; j < outputSize; j++) {
                    for (int k = 0; k < hiddenSize; k++) {
                        weights[i][j][k] = random.nextGaussian();
                    }
                }
                biases[i] = new double[outputSize][1];
                for (int j = 0; j < outputSize; j++) {
                    biases[i][j][0] = random.nextGaussian();
                }
            }
        }

        double[] inputs = new double[inputSize];
        for (int i = 0; i < inputSize; i++) {
            inputs[i] = random.nextGaussian();
        }

        double[] result = forward_pass(weights, biases, inputs);
        System.out.println(Arrays.toString(result));
    }
}