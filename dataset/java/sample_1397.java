import java.util.Random;

public class sample_1397 {
    public static double[][] init_weights(int size) {
        double[][] weights = new double[size][size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                weights[i][j] = rand.nextGaussian();
            }
        }
        return weights;
    }

    public static double[][] forward_pass(double[][] input_data, double[][] weights) {
        double[][] result = new double[input_data.length][weights[0].length];
        for (int i = 0; i < input_data.length; i++) {
            for (int j = 0; j < weights[0].length; j++) {
                for (int k = 0; k < weights.length; k++) {
                    result[i][j] += input_data[i][k] * weights[k][j];
                }
            }
        }
        return result;
    }

    public static boolean terminate_condition(double[][] data) {
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[0].length; j++) {
                if (data[i][j] >= 0.1) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int size = 5;
        double[][] weights = init_weights(size);
        double[][] data = new double[size][1];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            data[i][0] = rand.nextGaussian();
        }
        while (true) {
            data = forward_pass(data, weights);
            if (terminate_condition(data)) {
                break;
            }
        }
    }
}