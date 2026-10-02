import java.util.Arrays;

public class sample_2416 {
    public static double[][] forward_pass(double[][] weights, double[] biases, double[][] inputs) {
        double[][] x = new double[inputs.length][weights[0].length];
        for (int i = 0; i < inputs.length; i++) {
            for (int j = 0; j < weights[0].length; j++) {
                x[i][j] = biases[j];
                for (int k = 0; k < inputs[0].length; k++) {
                    x[i][j] += inputs[i][k] * weights[k][j];
                }
                if (x[i][j] < 0) {
                    x[i][j] = 0;
                }
            }
        }
        return x;
    }

    public static void main(String[] args) {
        double[][] weights = {{0.2, 0.3}, {0.4, 0.5}};
        double[] biases = {0.1, 0.2};
        double[][] inputs = {{1, 2}, {3, 4}};
        double[][] outputs = forward_pass(weights, biases, inputs);
        for (double[] row : outputs) {
            System.out.println(Arrays.toString(row));
        }
    }
}