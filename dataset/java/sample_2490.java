import java.util.Arrays;

public class sample_2490 {
    public static double[][] forward_pass(double[][] matrix, double[][] weights) {
        for (int i = 0; i < matrix.length; i++) {
            matrix[i] = dot(matrix[i], weights);
        }
        return matrix;
    }

    public static double[] dot(double[] a, double[][] b) {
        double[] result = new double[b[0].length];
        for (int j = 0; j < b[0].length; j++) {
            for (int k = 0; k < a.length; k++) {
                result[j] += a[k] * b[k][j];
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[][] data = {{1, 2}, {3, 4}, {5, 6}};
        double[][] w = {{0.5, 0.5}, {0.5, 0.5}};
        double[][] result = forward_pass(data, w);
        for (double[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }
}