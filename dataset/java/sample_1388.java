import java.util.ArrayList;
import java.util.List;

public class sample_1388 {

    public static List<double[]> transform_coordinates(List<double[]> points, double[][] matrix) {
        List<double[]> transformed = new ArrayList<>();
        for (double[] point : points) {
            double x = point[0];
            double y = point[1];
            double z = point[2];
            double x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
            double y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
            double z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
            transformed.add(new double[]{x_new, y_new, z_new});
        }
        return transformed;
    }

    public static List<double[]> apply_transformation() {
        List<double[]> points = new ArrayList<>();
        points.add(new double[]{1, 2, 3});
        points.add(new double[]{4, 5, 6});
        double[][] matrix = {
            {1, 0, 0, 1},
            {0, 1, 0, 2},
            {0, 0, 1, 3}
        };
        return transform_coordinates(points, matrix);
    }

    public static void main(String[] args) {
        List<double[]> result = apply_transformation();
        for (double[] point : result) {
            System.out.println("(" + point[0] + ", " + point[1] + ", " + point[2] + ")");
        }
    }
}