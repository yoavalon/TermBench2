import java.util.Random;

public class sample_2586 {
    public static double sigmoid(double x) {
        return 1 / (1 + Math.exp(-x));
    }

    public static double[][] forward_pass(double[][] weights, double[] bias, double[][] input_data) {
        int rows = input_data.length;
        int cols = weights[0].length;
        double[][] layer1 = new double[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < input_data[i].length; k++) {
                    layer1[i][j] += input_data[i][k] * weights[k][j];
                }
                layer1[i][j] += bias[j];
                layer1[i][j] = sigmoid(layer1[i][j]);
            }
        }

        return layer1;
    }

    public static void main(String[] args) {
        Random rand = new Random(0);
        double[][] weights = new double[3][4];
        double[] bias = new double[4];
        double[][] input_data = new double[4][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                weights[i][j] = rand.nextDouble();
            }
        }

        for (int i = 0; i < 4; i++) {
            bias[i] = rand.nextDouble();
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                input_data[i][j] = rand.nextDouble();
            }
        }

        double[][] result = forward_pass(weights, bias, input_data);
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[i].length; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }
}