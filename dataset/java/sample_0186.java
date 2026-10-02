import java.util.Random;

public class sample_0186 {
    public static double sigmoid(double x) {
        return 1 / (1 + Math.exp(-x));
    }

    public static double forward_pass(double[] weights, double bias, double[] input_data) {
        double z = 0;
        for (int i = 0; i < weights.length; i++) {
            z += weights[i] * input_data[i];
        }
        z += bias;
        return sigmoid(z);
    }

    public static void main(String[] args) {
        Random rand = new Random(0);
        double[] weights = new double[3];
        for (int i = 0; i < weights.length; i++) {
            weights[i] = rand.nextDouble();
        }
        double bias = rand.nextDouble();
        double[] input_data = {1, 2, 3};
        double output = forward_pass(weights, bias, input_data);
        System.out.println(output);
    }
}