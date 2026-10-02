import java.util.Arrays;

public class sample_2449 {

    public static double[][] transform_3d_coordinates(double[][] data, double[][] matrix) {
        double[][] transformed_data = new double[data.length][matrix[0].length];
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                transformed_data[i][j] = 0;
                for (int k = 0; k < matrix.length; k++) {
                    transformed_data[i][j] += data[i][k] * matrix[k][j];
                }
            }
        }
        return transformed_data;
    }

    public static void main(String[] args) {
        double[][] data = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        double[][] matrix = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 0, 0}
        };
        double[][] result = transform_3d_coordinates(data, matrix);
        System.out.println(Arrays.deepToString(result));
    }
}