import java.util.Arrays;

public class sample_0041 {

    public static double[][] transform_coordinates(double[][] coords, double[][] matrix) {
        double[][] result = new double[coords.length][matrix[0].length];
        for (int i = 0; i < coords.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                result[i][j] = 0;
                for (int k = 0; k < matrix.length; k++) {
                    result[i][j] += coords[i][k] * matrix[k][j];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[][] coords = {
            {1, 2, 3},
            {4, 5, 6}
        };
        double[][] matrix = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 0, 1}
        };
        double[][] result = transform_coordinates(coords, matrix);
        for (double[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }
}