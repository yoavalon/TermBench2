import java.util.Random;

public class sample_2816 {

    public static double[][] generate_data(int size) {
        double[][] data = new double[size][size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                data[i][j] = rand.nextDouble();
            }
        }
        return data;
    }

    public static double[] forward_pass(double[][] data, double[][] weights, double[] bias) {
        int size = data.length;
        double[] linear_output = new double[size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                linear_output[i] += data[i][j] * weights[j][i];
            }
            linear_output[i] += bias[i];
            if (linear_output[i] < 0) {
                linear_output[i] = 0;
            }
        }
        return linear_output;
    }

    public static void main(String[] args) {
        int size = 100;
        double[][] data = generate_data(size);
        double[][] weights = new double[size][size];
        double[] bias = new double[size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                weights[j][i] = rand.nextDouble();
            }
            bias[i] = rand.nextDouble();
        }
        while (true) {
            double[] activations = forward_pass(data, weights, bias);
        }
    }
}