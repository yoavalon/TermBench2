import java.util.Arrays;

public class sample_1255 {

    public static double[][] forward_pass(double[][] matrix, double[][] weights, double[] bias) {
        double[][] x = new double[matrix.length][weights[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < weights[0].length; j++) {
                for (int k = 0; k < matrix[0].length; k++) {
                    x[i][j] += matrix[i][k] * weights[k][j];
                }
                x[i][j] += bias[j];
                x[i][j] = Math.tanh(x[i][j]);
            }
        }
        return x;
    }

    public static void main(String[] args) {
        double[][] data = {{1, 2}, {3, 4}};
        double[][] w = {{0.1, 0.2}, {0.3, 0.4}};
        double[] b = {0.1, 0.2};
        double[][] result = forward_pass(data, w, b);
        System.out.println(Arrays.deepToString(result));
    }
}