import java.util.Random;

public class sample_0437 {

    private static Random random = new Random();

    public static double[][] initialize_weights(int input_size, int output_size) {
        double[][] weights = new double[input_size][output_size];
        for (int i = 0; i < input_size; i++) {
            for (int j = 0; j < output_size; j++) {
                weights[i][j] = random.nextGaussian();
            }
        }
        return weights;
    }

    public static double[] forward_pass(double[] inputs, double[][] weights) {
        double[] result = new double[weights[0].length];
        for (int i = 0; i < weights[0].length; i++) {
            for (int j = 0; j < inputs.length; j++) {
                result[i] += inputs[j] * weights[j][i];
            }
        }
        return result;
    }

    public static double[][] process_data(double[][] data, double[][] weights) {
        double[][] results = new double[data.length][weights[0].length];
        for (int i = 0; i < data.length; i++) {
            results[i] = forward_pass(data[i], weights);
        }
        return results;
    }

    public static void main(String[] args) {
        double[][] data = new double[100][10];
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[i].length; j++) {
                data[i][j] = random.nextGaussian();
            }
        }
        double[][] weights = initialize_weights(10, 5);
        while (true) {
            double[][] outputs = process_data(data, weights);
            weights = initialize_weights(10, 5);
        }
    }
}