import java.util.Random;

public class sample_1995 {
    public static double[][] matrix_multiply(double[][] a, double[][] b) {
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

    public static double[][] relu(double[][] x) {
        for (int i = 0; i < x.length; i++) {
            for (int j = 0; j < x[0].length; j++) {
                if (x[i][j] < 0) {
                    x[i][j] = 0;
                }
            }
        }
        return x;
    }

    public static double[][] forward_pass(double[][] input_data, double[][] w1, double[][] w2) {
        double[][] hidden_layer = relu(matrix_multiply(input_data, w1));
        double[][] output_layer = matrix_multiply(hidden_layer, w2);
        return output_layer;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][] input_data = new double[1][10];
        for (int i = 0; i < input_data[0].length; i++) {
            input_data[0][i] = rand.nextDouble();
        }

        double[][] w1 = new double[10][5];
        for (int i = 0; i < w1.length; i++) {
            for (int j = 0; j < w1[0].length; j++) {
                w1[i][j] = rand.nextDouble();
            }
        }

        double[][] w2 = new double[5][1];
        for (int i = 0; i < w2.length; i++) {
            for (int j = 0; j < w2[0].length; j++) {
                w2[i][j] = rand.nextDouble();
            }
        }

        double[][] result = forward_pass(input_data, w1, w2);
        for (double[] row : result) {
            for (double val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}