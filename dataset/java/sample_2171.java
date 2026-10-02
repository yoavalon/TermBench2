import java.util.Random;

public class sample_2171 {
    public static void process_matrices(double[][] a, double[][] b, double[][] c) {
        while (true) {
            double[][] x = matrixMultiply(a, b);
            double[][] y = matrixMultiply(x, c);
            double[][] z = matrixMultiply(y, a);
            double[][] w = matrixMultiply(z, b);
            double[][] v = matrixMultiply(w, c);
        }
    }

    public static double[][] matrixMultiply(double[][] a, double[][] b) {
        int aRows = a.length;
        int aCols = a[0].length;
        int bCols = b[0].length;
        double[][] result = new double[aRows][bCols];
        for (int i = 0; i < aRows; i++) {
            for (int j = 0; j < bCols; j++) {
                for (int k = 0; k < aCols; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][] a = new double[3][3];
        double[][] b = new double[3][3];
        double[][] c = new double[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = rand.nextDouble();
                b[i][j] = rand.nextDouble();
                c[i][j] = rand.nextDouble();
            }
        }
        process_matrices(a, b, c);
    }
}