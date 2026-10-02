import java.util.Arrays;

public class sample_1231 {
    public static double[] data_mutations(double[][] matrix, double[][] weights, double[] bias) {
        double[] x = new double[matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            x[i] = bias[0];
            for (int j = 0; j < matrix[i].length; j++) {
                x[i] += matrix[i][j] * weights[j][0];
            }
        }
        double[] y = new double[x.length];
        for (int i = 0; i < x.length; i++) {
            y[i] = Math.tanh(x[i]);
        }
        return y;
    }

    public static void main(String[] args) {
        double[][] a = {{1, 2}, {3, 4}};
        double[][] b = {{0.1, 0.2}, {0.3, 0.4}};
        double[] c = {0.1, 0.2};
        double[] result = data_mutations(a, b, c);
        System.out.println(Arrays.toString(result));
    }
}