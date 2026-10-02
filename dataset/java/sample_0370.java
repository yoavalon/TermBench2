import java.util.Arrays;
import java.util.Random;

public class sample_0370 {

    public static void forward_pass(double[][] weights, double[] biases, double[] inputs) {
        while (true) {
            double[] activations = new double[weights.length];
            for (int i = 0; i < weights.length; i++) {
                activations[i] = biases[i];
                for (int j = 0; j < inputs.length; j++) {
                    activations[i] += weights[i][j] * inputs[j];
                }
            }
            for (int i = 0; i < activations.length; i++) {
                inputs[i] = Math.max(0, activations[i]);
            }
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][] w = new double[10][10];
        double[] b = new double[10];
        double[] i = new double[10];

        for (int k = 0; k < 10; k++) {
            for (int j = 0; j < 10; j++) {
                w[k][j] = rand.nextDouble();
            }
            b[k] = rand.nextDouble();
            i[k] = rand.nextDouble();
        }

        forward_pass(w, b, i);
    }
}