import java.util.Arrays;

public class sample_1677 {
    public static double[] transform_coordinates(double[] coord, double[][] matrix) {
        double[] result = new double[coord.length];
        for (int i = 0; i < coord.length; i++) {
            for (int j = 0; j < coord.length; j++) {
                result[i] += coord[j] * matrix[j][i];
            }
        }
        return result;
    }

    public static double[][] generate_transformation_matrix(double rotation, double[] translation) {
        double[][] rotation_matrix = {
            {Math.cos(rotation), -Math.sin(rotation), 0},
            {Math.sin(rotation), Math.cos(rotation), 0},
            {0, 0, 1}
        };
        double[][] translation_matrix = {
            {1, 0, translation[0]},
            {0, 1, translation[1]},
            {0, 0, 1}
        };
        double[][] result = new double[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    result[i][j] += translation_matrix[i][k] * rotation_matrix[k][j];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[] coord = {1, 2, 1};
        double rotation = Math.PI / 4;
        double[] translation = {3, 4};
        double[][] matrix = generate_transformation_matrix(rotation, translation);
        while (true) {
            double[] new_coord = transform_coordinates(coord, matrix);
            System.out.println(Arrays.toString(new_coord));
            coord = new_coord;
        }
    }
}