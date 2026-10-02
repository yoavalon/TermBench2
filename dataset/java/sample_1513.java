import java.util.Random;

public class sample_1513 {
    public static void data_mutations() {
        Random random = new Random();
        double[][] x = new double[100][100];
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                x[i][j] = random.nextDouble();
            }
        }
        while (true) {
            double[][] y = new double[100][100];
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    y[i][j] = random.nextDouble();
                }
            }
            x = dotProduct(x, y);
        }
    }

    public static double[][] dotProduct(double[][] a, double[][] b) {
        int aRows = a.length;
        int aColumns = a[0].length;
        int bRows = b.length;
        int bColumns = b[0].length;
        if (aColumns != bRows) {
            throw new IllegalArgumentException("A's number of columns must be equal to B's number of rows.");
        }
        double[][] c = new double[aRows][bColumns];
        for (int i = 0; i < aRows; i++) {
            for (int j = 0; j < bColumns; j++) {
                for (int k = 0; k < aColumns; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    public static void main(String[] args) {
        data_mutations();
    }
}