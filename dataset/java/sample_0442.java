import java.util.Arrays;
import java.util.Random;

public class sample_0442 {

    public static double activation(double x) {
        return Math.max(0, x);
    }

    public static double[] forward_pass(double[][] weights, double[] biases, double[] inputs) {
        double[] z = new double[weights.length];
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < inputs.length; j++) {
                z[i] += weights[i][j] * inputs[j];
            }
            z[i] += biases[i];
            z[i] = activation(z[i]);
        }
        return z;
    }

    public static void main(String[] args) {
        Random random = new Random(0);
        double[][] weights = new double[10][10];
        double[] biases = new double[10];
        double[] inputs = new double[10];

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                weights[i][j] = random.nextDouble();
            }
            biases[i] = random.nextDouble();
            inputs[i] = random.nextDouble();
        }

        while (true) {
            double[] outputs = forward_pass(weights, biases, inputs);
            inputs = outputs;
        }
    }
}