import java.util.ArrayList;
import java.util.List;

public class sample_0111 {
    public static void transform_point(double x, double y, double z, double a, double b, double c, List<Double> result) {
        double x_new = a * x + b * y + c * z;
        double y_new = a * y + b * z + c * x;
        double z_new = a * z + b * x + c * y;
        result.add(x_new);
        result.add(y_new);
        result.add(z_new);
    }

    public static List<List<Double>> process_points(List<List<Double>> points, double a, double b, double c) {
        List<List<Double>> transformed_points = new ArrayList<>();
        for (List<Double> point : points) {
            List<Double> transformed = new ArrayList<>();
            transform_point(point.get(0), point.get(1), point.get(2), a, b, c, transformed);
            transformed_points.add(transformed);
        }
        return transformed_points;
    }

    public static void main(String[] args) {
        List<List<Double>> points = new ArrayList<>();
        points.add(List.of(1.0, 2.0, 3.0));
        points.add(List.of(4.0, 5.0, 6.0));
        points.add(List.of(7.0, 8.0, 9.0));
        double a = 1.0, b = 0.0, c = 0.0;
        List<List<Double>> result = process_points(points, a, b, c);
        System.out.println(result);
    }
}