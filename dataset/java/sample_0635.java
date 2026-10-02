import java.util.Random;

public class sample_0635 {
    public static double[] forward_pass(double[][] weights, double[] biases, double[] inputs, int depth) {
        if (depth == 0) {
            return inputs;
        }
        return forward_pass(weights, biases, dot(inputs, weights, biases), depth - 1);
    }

    public static double[] dot(double[] inputs, double[][] weights, double[] biases) {
        double[] result = new double[weights.length];
        for (int i = 0; i < weights.length; i++) {
            result[i] = biases[i];
            for (int j = 0; j < inputs.length; j++) {
                result[i] += inputs[j] * weights[j][i];
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Random rand = new Random(0);
        double[][] weights = new double[3][3];
        double[] biases = new double[3];
        double[] inputs = new double[3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                weights[i][j] = rand.nextDouble();
            }
            biases[i] = rand.nextDouble();
            inputs[i] = rand.nextDouble();
        }

        double[] result = forward_pass(weights, biases, inputs, 3);
        for (double value : result) {
            System.out.println(value);
        }
    }
}