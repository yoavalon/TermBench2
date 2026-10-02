import java.util.Arrays;

public class sample_2412 {

    public static double[][] forward_pass(double[][] matrix, double[][] weights, double[] bias) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int weightRows = weights.length;
        int weightCols = weights[0].length;

        double[][] layer1 = new double[rows][weightCols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < weightCols; j++) {
                for (int k = 0; k < cols; k++) {
                    layer1[i][j] += matrix[i][k] * weights[k][j];
                }
                layer1[i][j] += bias[j];
            }
        }

        double[][] layer2 = new double[rows][weightCols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < weightCols; j++) {
                layer2[i][j] = Math.max(layer1[i][j], 0);
            }
        }

        return layer2;
    }

    public static void main(String[] args) {
        double[][] matrix = {{1, 2}, {3, 4}};
        double[][] weights = {{0.1, 0.2}, {0.3, 0.4}};
        double[] bias = {0.1, 0.2};
        double[][] result = forward_pass(matrix, weights, bias);
        System.out.println(Arrays.deepToString(result));
    }
}