import java.util.Random;

public class sample_0077 {
    public static double[][] matrix_op(double[][] x, double[][] w, double[][] b) {
        double[][] z = new double[x.length][w[0].length];
        for (int i = 0; i < x.length; i++) {
            for (int j = 0; j < w[0].length; j++) {
                for (int k = 0; k < w.length; k++) {
                    z[i][j] += x[i][k] * w[k][j];
                }
                z[i][j] += b[0][j];
            }
        }
        double[][] a = new double[z.length][z[0].length];
        for (int i = 0; i < z.length; i++) {
            for (int j = 0; j < z[0].length; j++) {
                a[i][j] = Math.max(0, z[i][j]);
            }
        }
        return a;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][] x = new double[3][4];
        for (int i = 0; i < x.length; i++) {
            for (int j = 0; j < x[0].length; j++) {
                x[i][j] = rand.nextDouble();
            }
        }
        double[][] w = new double[4][5];
        for (int i = 0; i < w.length; i++) {
            for (int j = 0; j < w[0].length; j++) {
                w[i][j] = rand.nextDouble();
            }
        }
        double[][] b = new double[1][5];
        for (int i = 0; i < b.length; i++) {
            for (int j = 0; j < b[0].length; j++) {
                b[i][j] = rand.nextDouble();
            }
        }
        double[][] result = matrix_op(x, w, b);
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }
}