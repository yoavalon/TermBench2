import java.util.Random;

public class sample_1052 {

    public static double sigmoid(double x) {
        return 1 / (1 + Math.exp(-x));
    }

    public static double[] forward_pass(double[][] weights, double[] biases, double[] input_data) {
        double[] x = new double[weights.length];
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < weights[i].length; j++) {
                x[i] += weights[i][j] * input_data[j];
            }
            x[i] += biases[i];
        }
        for (int i = 0; i < x.length; i++) {
            x[i] = sigmoid(x[i]);
        }
        return x;
    }

    public static double[] recursive_forward(double[][] weights, double[] biases, double[] input_data) {
        double[] output = forward_pass(weights, biases, input_data);
        return recursive_forward(weights, biases, output);
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][] weights = new double[10][10];
        double[] biases = new double[10];
        double[] input_data = new double[10];

        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < weights[i].length; j++) {
                weights[i][j] = rand.nextDouble();
            }
            biases[i] = rand.nextDouble();
            input_data[i] = rand.nextDouble();
        }

        recursive_forward(weights, biases, input_data);
    }
}