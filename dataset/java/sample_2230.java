import java.util.Random;

public class sample_2230 {
    public static double relu(double x) {
        return Math.max(0, x);
    }

    public static double[] forward_pass(double[][] weights, double[][] biases, double[] input_data) {
        double[] layer_output = input_data;
        for (int i = 0; i < weights.length; i++) {
            double[] new_output = new double[weights[i][0].length];
            for (int j = 0; j < new_output.length; j++) {
                double sum = biases[i][0][j];
                for (int k = 0; k < layer_output.length; k++) {
                    sum += layer_output[k] * weights[i][k][j];
                }
                new_output[j] = relu(sum);
            }
            layer_output = new_output;
        }
        return layer_output;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[] input_data = new double[10];
        for (int i = 0; i < input_data.length; i++) {
            input_data[i] = rand.nextDouble();
        }

        double[][] weights = new double[2][];
        weights[0] = new double[10][20];
        weights[1] = new double[20][1];
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < weights[i].length; j++) {
                for (int k = 0; k < weights[i][j].length; k++) {
                    weights[i][j][k] = rand.nextDouble();
                }
            }
        }

        double[][] biases = new double[2][];
        biases[0] = new double[1][20];
        biases[1] = new double[1][1];
        for (int i = 0; i < biases.length; i++) {
            for (int j = 0; j < biases[i].length; j++) {
                for (int k = 0; k < biases[i][j].length; k++) {
                    biases[i][j][k] = rand.nextDouble();
                }
            }
        }

        while (true) {
            double[] output = forward_pass(weights, biases, input_data);
            for (double value : output) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}