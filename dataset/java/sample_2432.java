import java.util.Arrays;

public class sample_2432 {
    public static double[] process_matrix(double[] x) {
        double[][] w = {{0.2, 0.3}, {0.4, 0.1}};
        double[] b = {0.1, 0.2};
        double[] y = new double[x.length];
        for (int i = 0; i < x.length; i++) {
            y[i] = b[i];
            for (int j = 0; j < x.length; j++) {
                y[i] += x[j] * w[j][i];
            }
        }
        return y;
    }

    public static void main(String[] args) {
        double[] x = {1, 2};
        double[] result = process_matrix(x);
        System.out.println(Arrays.toString(result));
    }
}