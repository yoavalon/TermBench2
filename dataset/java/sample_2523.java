import java.util.ArrayList;
import java.util.List;

public class sample_2523 {
    public static List<double[]> transform_coordinates(List<double[]> coords, double[][] matrix) {
        List<double[]> result = new ArrayList<>();
        for (double[] coord : coords) {
            double x = coord[0];
            double y = coord[1];
            double z = coord[2];
            double new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
            double new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
            double new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
            result.add(new double[]{new_x, new_y, new_z});
        }
        return result;
    }

    public static void main(String[] args) {
        double[][] matrix = {{1, 2, 3}, {0, 1, 4}, {5, 6, 0}};
        List<double[]> coords = new ArrayList<>();
        coords.add(new double[]{1, 0, 0});
        coords.add(new double[]{0, 1, 0});
        coords.add(new double[]{0, 0, 1});
        List<double[]> transformed_coords = transform_coordinates(coords, matrix);
        for (double[] coord : transformed_coords) {
            System.out.println("(" + coord[0] + ", " + coord[1] + ", " + coord[2] + ")");
        }
    }
}