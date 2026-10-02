import java.util.Arrays;

public class sample_2499 {

    public static double[] forward_pass(double[][] matrix, double[][] weights, double[] bias) {
        double[] result = new double[matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            result[i] = bias[i];
            for (int j = 0; j < matrix[i].length; j++) {
                result[i] += matrix[i][j] * weights[j][i];
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[][] a = {{1, 2}, {3, 4}};
        double[][] w = {{0.1, 0.2}, {0.3, 0.4}};
        double[] b = {0.5, 0.6};
        double[] result = forward_pass(a, w, b);
        System.out.println(Arrays.toString(result));
    }
}