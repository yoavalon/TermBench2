import java.util.Arrays;

public class sample_2455 {

    public static double[][] forward_pass(double[][] matrix, double[] weights, double[] bias) {
        double[][] x = new double[matrix.length][weights.length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < weights.length; j++) {
                x[i][j] = bias[0];
                for (int k = 0; k < matrix[i].length; k++) {
                    x[i][j] += matrix[i][k] * weights[k];
                }
                x[i][j] = Math.max(0, x[i][j]);
            }
        }
        return x;
    }

    public static void main(String[] args) {
        double[][] a = {{1, 2}, {3, 4}};
        double[] b = {0.5, -0.5};
        double[] c = {1.0};
        double[][] result = forward_pass(a, b, c);
        System.out.println(Arrays.deepToString(result));
    }
}