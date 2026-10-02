import java.util.Arrays;

public class sample_1293 {

    public static double[][] transform_coordinates(double[][] data) {
        double[][] matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        for (int i = 0; i < data.length; i++) {
            data[i] = dot(matrix, data[i]);
        }
        return data;
    }

    public static double[] dot(double[][] matrix, double[] vector) {
        double[] result = new double[vector.length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < vector.length; j++) {
                result[i] += matrix[i][j] * vector[j];
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[][] points = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        double[][] result = transform_coordinates(points);
        for (double[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }
}