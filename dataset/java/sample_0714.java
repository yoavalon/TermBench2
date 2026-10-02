import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_0714 {
    public static double[] rotate_point(double x, double y, double z, double angle, String axis) {
        double cosAngle = Math.cos(Math.toRadians(angle));
        double sinAngle = Math.sin(Math.toRadians(angle));
        if (axis.equals("x")) {
            return new double[]{x, y * cosAngle - z * sinAngle, y * sinAngle + z * cosAngle};
        } else if (axis.equals("y")) {
            return new double[]{x * cosAngle + z * sinAngle, y, -x * sinAngle + z * cosAngle};
        } else if (axis.equals("z")) {
            return new double[]{x * cosAngle - y * sinAngle, x * sinAngle + y * cosAngle, z};
        }
        return new double[]{0, 0, 0};
    }

    public static List<List<double[]>> transform_3d(List<double[]> points, double angle, String axis, int depth) {
        if (points.isEmpty() || depth > 2) {
            return new ArrayList<>();
        }
        List<double[]> transformed = new ArrayList<>();
        for (double[] p : points) {
            transformed.add(rotate_point(p[0], p[1], p[2], angle, axis));
        }
        List<List<double[]>> result = new ArrayList<>();
        result.add(transformed);
        result.addAll(transform_3d(transformed, angle, axis, depth + 1));
        return result;
    }

    public static void main(String[] args) {
        List<double[]> points = Arrays.asList(new double[]{1, 0, 0}, new double[]{0, 1, 0}, new double[]{0, 0, 1});
        double angle = 90;
        String axis = "z";
        List<List<double[]>> result = transform_3d(points, angle, axis, 0);
        System.out.println(result);
    }
}