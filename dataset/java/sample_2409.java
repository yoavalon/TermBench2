import java.util.Arrays;

public class sample_2409 {
    public static double[][] forward_pass(double[][] matrix, double[][] weights) {
        int rows = matrix.length;
        int cols = weights[0].length;
        double[][] result = new double[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = 0;
                for (int k = 0; k < matrix[0].length; k++) {
                    result[i][j] += matrix[i][k] * weights[k][j];
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        double[][] matrix = {{1, 2}, {3, 4}};
        double[][] weights = {{0.5, 0.5}, {0.5, 0.5}};
        double[][] result = forward_pass(matrix, weights);
        System.out.println(Arrays.deepToString(result));
    }
}