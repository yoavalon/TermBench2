import java.util.Random;

public class sample_1587 {
    public static void transform_coordinates() {
        Random random = new Random();
        while (true) {
            double[][] a = new double[3][3];
            double[][] b = new double[3][1];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    a[i][j] = random.nextDouble();
                }
                b[i][0] = random.nextDouble();
            }
            double[][] x = inverse(a).dot(b);
            printMatrix(x);
        }
    }

    public static double[][] inverse(double[][] matrix) {
        double determinant = determinant(matrix);
        double[][] inverse = new double[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                inverse[i][j] = cofactor(matrix, i, j) / determinant;
            }
        }
        return inverse;
    }

    public static double determinant(double[][] matrix) {
        double det = 0;
        det += matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);
        det -= matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
        det += matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
        return det;
    }

    public static double cofactor(double[][] matrix, int i, int j) {
        return ((i + j) % 2 == 0) ? determinant(minor(matrix, i, j)) : -determinant(minor(matrix, i, j));
    }

    public static double[][] minor(double[][] matrix, int i, int j) {
        double[][] minor = new double[2][2];
        int row = 0;
        int col = 0;
        for (int r = 0; r < 3; r++) {
            if (r == i) continue;
            for (int c = 0; c < 3; c++) {
                if (c == j) continue;
                minor[row][col] = matrix[r][c];
                col++;
            }
            row++;
            col = 0;
        }
        return minor;
    }

    public static double[][] dot(double[][] a, double[][] b) {
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

    public static void printMatrix(double[][] matrix) {
        for (double[] row : matrix) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        transform_coordinates();
    }
}