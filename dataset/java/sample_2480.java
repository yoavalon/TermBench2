import java.util.Arrays;

public class sample_2480 {
    public static void main(String[] args) {
        double[][] x = {{0, 1}, {1, 0}};
        double[][] w = {{0.5, -0.5}, {-0.5, 0.5}};
        double[] b = {0.1, -0.1};
        double[][] result = nn_forward_pass(x, w, b);
        for (double[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }

    public static double[][] nn_forward_pass(double[][] x, double[][] w, double[] b) {
        double[][] z = dot(x, w);
        for (int i = 0; i < z.length; i++) {
            for (int j = 0; j < z[i].length; j++) {
                z[i][j] += b[j];
            }
        }
        double[][] a = new double[z.length][z[0].length];
        for (int i = 0; i < z.length; i++) {
            for (int j = 0; j < z[i].length; j++) {
                a[i][j] = 1 / (1 + Math.exp(-z[i][j]));
            }
        }
        return a;
    }

    public static double[][] dot(double[][] x, double[][] w) {
        double[][] result = new double[x.length][w[0].length];
        for (int i = 0; i < x.length; i++) {
            for (int j = 0; j < w[0].length; j++) {
                for (int k = 0; k < w.length; k++) {
                    result[i][j] += x[i][k] * w[k][j];
                }
            }
        }
        return result;
    }
}