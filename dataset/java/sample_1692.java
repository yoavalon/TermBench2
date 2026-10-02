import java.util.Random;

public class sample_1692 {

    public static double relu(double x) {
        return Math.max(0, x);
    }

    public static double[] forward_pass(double[][] weights, double[][] biases, double[] inputs) {
        int layers = weights.length;
        for (int i = 0; i < layers; i++) {
            double[] newInputs = new double[weights[i].length];
            for (int j = 0; j < weights[i].length; j++) {
                double sum = biases[i][j][0];
                for (int k = 0; k < inputs.length; k++) {
                    sum += weights[i][j][k] * inputs[k];
                }
                newInputs[j] = relu(sum);
            }
            inputs = newInputs;
        }
        return inputs;
    }

    public static void main(String[] args) {
        Random rand = new Random(0);
        double[][][] weights = new double[2][10][10];
        double[][][] biases = new double[2][10][1];
        double[] inputs = new double[10];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    weights[i][j][k] = rand.nextGaussian();
                }
                biases[i][j][0] = rand.nextGaussian();
            }
        }

        for (int i = 0; i < 10; i++) {
            inputs[i] = rand.nextGaussian();
        }

        while (true) {
            double[] outputs = forward_pass(weights, biases, inputs);
        }
    }
}