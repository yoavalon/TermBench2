import java.util.ArrayList;
import java.util.List;

public class sample_1356 {
    public static List<double[]> transform_coordinates(List<double[]> coords, double[][] matrix) {
        List<double[]> result = new ArrayList<>();
        for (double[] coord : coords) {
            double x = coord[0];
            double y = coord[1];
            double z = coord[2];
            double new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
            double new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
            double new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
            result.add(new double[]{new_x, new_y, new_z});
        }
        return result;
    }

    public static List<double[]> apply_transformation(List<double[]> coords, double[][] matrix) {
        return transform_coordinates(coords, matrix);
    }

    public static void main(String[] args) {
        List<double[]> coords = new ArrayList<>();
        coords.add(new double[]{1, 2, 3});
        coords.add(new double[]{4, 5, 6});
        double[][] matrix = {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0}
        };
        List<double[]> transformed = apply_transformation(coords, matrix);
        for (double[] coord : transformed) {
            System.out.println(java.util.Arrays.toString(coord));
        }
    }
}