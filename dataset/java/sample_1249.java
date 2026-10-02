import java.util.Arrays;

public class sample_1249 {

    public static double[][] transform_coordinates(double[][] points, double[][] matrix) {
        double[][] result = new double[points.length][matrix[0].length];
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                result[i][j] = 0;
                for (int k = 0; k < matrix.length; k++) {
                    result[i][j] += points[i][k] * matrix[k][j];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[][] points = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        double[][] matrix = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 0, 0}
        };
        double[][] transformed = transform_coordinates(points, matrix);
        for (double[] row : transformed) {
            System.out.println(Arrays.toString(row));
        }
    }
}