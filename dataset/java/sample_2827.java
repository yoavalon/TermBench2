import java.util.List;
import java.util.ArrayList;

public class sample_2827 {
    public static void main(String[] args) {
        List<double[]> points = new ArrayList<>();
        points.add(new double[]{1, 0, 0});
        points.add(new double[]{0, 1, 0});
        points.add(new double[]{0, 0, 1});
        double angle = 10;
        transform_sequence(points, angle);
    }

    public static double[] rotate_point(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double cos_a = Math.cos(rad);
        double sin_a = Math.sin(rad);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        return new double[]{x_new, y_new, z};
    }

    public static void transform_sequence(List<double[]> points, double angle) {
        while (true) {
            for (int i = 0; i < points.size(); i++) {
                double[] point = points.get(i);
                double[] new_point = rotate_point(point[0], point[1], point[2], angle);
                points.set(i, new_point);
            }
        }
    }
}