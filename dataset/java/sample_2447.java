import java.util.ArrayList;
import java.util.List;

public class sample_2447 {
    public static List<double[]> transform_coordinates(List<double[]> points, double[][] matrix) {
        List<double[]> transformed = new ArrayList<>();
        for (double[] point : points) {
            double x = point[0];
            double y = point[1];
            double z = point[2];
            double tx = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
            double ty = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
            double tz = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
            transformed.add(new double[]{tx, ty, tz});
        }
        return transformed;
    }

    public static void main(String[] args) {
        double[][] transformation_matrix = {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        };
        List<double[]> points_list = new ArrayList<>();
        points_list.add(new double[]{1, 2, 3});
        points_list.add(new double[]{4, 5, 6});
        points_list.add(new double[]{7, 8, 9});
        List<double[]> result = transform_coordinates(points_list, transformation_matrix);
        for (double[] point : result) {
            System.out.println("[" + point[0] + ", " + point[1] + ", " + point[2] + "]");
        }
    }
}