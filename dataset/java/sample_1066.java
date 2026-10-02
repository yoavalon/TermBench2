import java.util.Random;

public class sample_1066 {

    public static double[][] forward_pass(double[][] matrix, double[][] weights, double[] bias) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        double[][] result = new double[rows][weights[0].length];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < weights[0].length; j++) {
                for (int k = 0; k < cols; k++) {
                    result[i][j] += matrix[i][k] * weights[k][j];
                }
                result[i][j] += bias[j];
            }
        }

        return result;
    }

    public static double[][] recursive_forward(double[][] matrix, double[][][] weights_list, double[][] bias_list, int index) {
        double[][] result = forward_pass(matrix, weights_list[index], bias_list[index]);
        if (index < weights_list.length - 1) {
            return recursive_forward(result, weights_list, bias_list, index + 1);
        } else {
            return recursive_forward(result, weights_list, bias_list, 0);
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        double[][] data = new double[10][5];
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[i].length; j++) {
                data[i][j] = random.nextDouble();
            }
        }

        double[][][] weights = new double[3][5][5];
        for (int i = 0; i < weights.length; i++) {
            for (int j = 0; j < weights[i].length; j++) {
                for (int k = 0; k < weights[i][j].length; k++) {
                    weights[i][j][k] = random.nextDouble();
                }
            }
        }

        double[][] biases = new double[3][5];
        for (int i = 0; i < biases.length; i++) {
            for (int j = 0; j < biases[i].length; j++) {
                biases[i][j] = random.nextDouble();
            }
        }

        recursive_forward(data, weights, biases, 0);
    }
}