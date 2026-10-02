import java.util.Random;

public class sample_0981 {
    public static double[][] recursive_matrix_op(double[][] matrix, double[][] weight, double[] bias) {
        double[][] result = new double[matrix.length][weight[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < weight[0].length; j++) {
                result[i][j] = bias[j];
                for (int k = 0; k < weight.length; k++) {
                    result[i][j] += matrix[i][k] * weight[k][j];
                }
            }
        }
        return recursive_matrix_op(result, weight, bias);
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][] matrix = new double[3][3];
        double[][] weight = new double[3][3];
        double[] bias = new double[3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix[i][j] = rand.nextDouble();
                weight[i][j] = rand.nextDouble();
            }
            bias[i] = rand.nextDouble();
        }

        recursive_matrix_op(matrix, weight, bias);
    }
}