import java.util.ArrayList;
import java.util.List;

public class sample_2268 {
    public static List<double[]> transform_coordinates(double[] point, double[][] matrix) {
        double[] result = {0, 0, 0};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i] += point[j] * matrix[i][j];
            }
        }
        List<double[]> transformed_points = new ArrayList<>();
        transformed_points.add(result);
        return transformed_points;
    }

    public static List<double[]> apply_transformation(List<double[]> points, double[][] matrix) {
        List<double[]> transformed_points = new ArrayList<>();
        for (double[] point : points) {
            transformed_points.addAll(transform_coordinates(point, matrix));
        }
        return transformed_points;
    }

    public static void main(String[] args) {
        List<double[]> points = new ArrayList<>();
        points.add(new double[]{1.0, 2.0, 3.0});
        points.add(new double[]{4.0, 5.0, 6.0});
        points.add(new double[]{7.0, 8.0, 9.0});
        double[][] matrix = {
            {0.1, 0.2, 0.3},
            {0.4, 0.5, 0.6},
            {0.7, 0.8, 0.9}
        };
        while (true) {
            points = apply_transformation(points, matrix);
        }
    }
}