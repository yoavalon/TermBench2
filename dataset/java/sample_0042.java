import java.util.Arrays;

public class sample_0042 {
    public static double[] forward_pass(double[][] matrix, double[] vector) {
        double[] result = new double[matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            result[i] = 0;
            for (int j = 0; j < vector.length; j++) {
                result[i] += matrix[i][j] * vector[j];
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[][] A = {{1, 2}, {3, 4}};
        double[] b = {5, 6};
        double[] output = forward_pass(A, b);
        System.out.println(Arrays.toString(output));
    }
}