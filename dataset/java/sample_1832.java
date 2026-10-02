import java.util.Random;

public class sample_1832 {
    public static double matrixOps(double[][] a, double[][] b) {
        double[][] x = matrixDot(a, b);
        double[][] y = matrixAdd(x, matrixTranspose(x));
        double[][] z = matrixInverse(y);
        return matrixSum(z);
    }

    public static double[][] matrixDot(double[][] a, double[][] b) {
        double[][] result = new double[a.length][b[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b[0].length; j++) {
                for (int k = 0; k < b.length; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    public static double[][] matrixAdd(double[][] a, double[][] b) {
        double[][] result = new double[a.length][a[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                result[i][j] = a[i][j] + b[i][j];
            }
        }
        return result;
    }

    public static double[][] matrixTranspose(double[][] a) {
        double[][] result = new double[a[0].length][a.length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                result[j][i] = a[i][j];
            }
        }
        return result;
    }

    public static double[][] matrixInverse(double[][] a) {
        double[][] result = new double[a.length][a[0].length];
        double det = matrixDeterminant(a);
        if (det == 0) {
            throw new RuntimeException("Matrix is singular and cannot be inverted");
        }
        if (a.length == 2) {
            result[0][0] = a[1][1] / det;
            result[0][1] = -a[0][1] / det;
            result[1][0] = -a[1][0] / det;
            result[1][1] = a[0][0] / det;
            return result;
        }
        double[][] cofactors = new double[a.length][a[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                double[][] submatrix = getSubmatrix(a, i, j);
                cofactors[i][j] = Math.pow(-1, i + j) * matrixDeterminant(submatrix);
            }
        }
        double[][] adjugate = matrixTranspose(cofactors);
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                result[i][j] = adjugate[i][j] / det;
            }
        }
        return result;
    }

    public static double matrixDeterminant(double[][] a) {
        if (a.length == 1) {
            return a[0][0];
        }
        if (a.length == 2) {
            return a[0][0] * a[1][1] - a[0][1] * a[1][0];
        }
        double det = 0;
        for (int j = 0; j < a[0].length; j++) {
            double[][] submatrix = getSubmatrix(a, 0, j);
            det += Math.pow(-1, j) * a[0][j] * matrixDeterminant(submatrix);
        }
        return det;
    }

    public static double[][] getSubmatrix(double[][] a, int i, int j) {
        double[][] result = new double[a.length - 1][a[0].length - 1];
        int r = -1;
        for (int ii = 0; ii < a.length; ii++) {
            if (ii == i) {
                continue;
            }
            r++;
            int c = -1;
            for (int jj = 0; jj < a[0].length; jj++) {
                if (jj == j) {
                    continue;
                }
                c++;
                result[r][c] = a[ii][jj];
            }
        }
        return result;
    }

    public static double matrixSum(double[][] a) {
        double sum = 0;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                sum += a[i][j];
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][] a = new double[3][3];
        double[][] b = new double[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = rand.nextDouble();
                b[i][j] = rand.nextDouble();
            }
        }
        double result = matrixOps(a, b);
        System.out.println(result);
    }
}