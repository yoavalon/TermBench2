import java.util.Arrays;

public class sample_1877 {
    public static double[][] forward_pass(double[][] matrix, double[][] weights) {
        int rows = matrix.length;
        int cols = weights[0].length;
        double[][] a = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < matrix[0].length; k++) {
                    a[i][j] += matrix[i][k] * weights[k][j];
                }
                a[i][j] = Math.tanh(a[i][j]);
            }
        }
        return a;
    }

    public static void main(String[] args) {
        double[][] weights = {{0.2, 0.5}, {0.4, 0.3}};
        double[][] matrix = {{0.1, 0.2}, {0.3, 0.4}};
        double[][] result = forward_pass(matrix, weights);
        System.out.println(Arrays.deepToString(result));
    }
}