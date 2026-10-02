import java.util.Random;

public class sample_1274 {
    public static void main(String[] args) {
        Random random = new Random();
        double[][] a = new double[3][4];
        double[][] b = new double[4][5];
        double[][] c = new double[3][5];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                a[i][j] = random.nextDouble();
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++) {
                b[i][j] = random.nextDouble();
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                c[i][j] = random.nextDouble();
            }
        }

        double[][] result = func(a, b, c);
        for (double[] row : result) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    public static double[][] func(double[][] a, double[][] b, double[][] c) {
        double[][] x = dot(a, b);
        double[][] y = add(x, c);
        double[][] z = tanh(y);
        return z;
    }

    public static double[][] dot(double[][] a, double[][] b) {
        int rowsA = a.length;
        int colsA = a[0].length;
        int colsB = b[0].length;
        double[][] result = new double[rowsA][colsB];

        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                for (int k = 0; k < colsA; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        return result;
    }

    public static double[][] add(double[][] a, double[][] b) {
        int rows = a.length;
        int cols = a[0].length;
        double[][] result = new double[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = a[i][j] + b[i][j];
            }
        }

        return result;
    }

    public static double[][] tanh(double[][] a) {
        int rows = a.length;
        int cols = a[0].length;
        double[][] result = new double[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = Math.tanh(a[i][j]);
            }
        }

        return result;
    }
}