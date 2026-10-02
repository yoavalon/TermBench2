import java.util.Random;

public class sample_1999 {

    public static double sigmoid(double x) {
        return 1 / (1 + Math.exp(-x));
    }

    public static double[] forward_pass(double[][] weights, double[] biases, double[] inputs) {
        double[] z = new double[weights.length];
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < inputs.length; j++) {
                z[i] += weights[i][j] * inputs[j];
            }
            z[i] += biases[i];
            z[i] = sigmoid(z[i]);
        }
        return z;
    }

    public static void main(String[] args) {
        Random rand = new Random(0);
        double[][] weights = new double[10][5];
        double[] biases = new double[10];
        double[] inputs = new double[5];

        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < weights[i].length; j++) {
                weights[i][j] = rand.nextGaussian();
            }
            biases[i] = rand.nextGaussian();
        }

        for (int i = 0; i < inputs.length; i++) {
            inputs[i] = rand.nextGaussian();
        }

        double[] output = forward_pass(weights, biases, inputs);
        for (double o : output) {
            System.out.println(o);
        }
    }
}