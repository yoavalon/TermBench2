import java.util.Arrays;

public class sample_2431 {
    public static double[][] neural_net_forward_pass(double[][] matrix, double[][] weights, double[] bias) {
        double[][] x = new double[matrix.length][weights[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < weights[0].length; j++) {
                for (int k = 0; k < weights.length; k++) {
                    x[i][j] += matrix[i][k] * weights[k][j];
                }
                x[i][j] += bias[j];
                if (x[i][j] < 0) {
                    x[i][j] = 0;
                }
            }
        }
        return x;
    }

    public static void main(String[] args) {
        double[][] mat = {{1, 2}, {3, 4}};
        double[][] w = {{0.5, -0.5}, {-0.5, 0.5}};
        double[] b = {0.1, -0.1};
        double[][] result = neural_net_forward_pass(mat, w, b);
        for (double[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }
}