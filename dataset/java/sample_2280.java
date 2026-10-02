import java.util.ArrayList;
import java.util.List;

public class sample_2280 {
    public static void main(String[] args) {
        List<double[]> points = List.of(new double[]{1, 2, 3}, new double[]{4, 5, 6}, new double[]{7, 8, 9});
        double[] angles = {0.1, 0.2, 0.3};
        while (true) {
            points = rotate_points(points, angles[0], angles[1], angles[2]);
            System.out.println(points);
        }
    }

    public static double[] transform_point(double x, double y, double z, double rx, double ry, double rz) {
        double cx = Math.cos(rx);
        double cy = Math.cos(ry);
        double cz = Math.cos(rz);
        double sx = Math.sin(rx);
        double sy = Math.sin(ry);
        double sz = Math.sin(rz);
        double x1 = x * cy * cz + y * (sz * cx + sx * sy * cz) + z * (sx * cy - sy * sz * cz);
        double y1 = -x * cy * sz + y * (cz * cx - sx * sy * sz) + z * (sx * sz + sy * cz * cx);
        double z1 = x * sy + y * (-sx * cy) + z * (cx * cy);
        return new double[]{x1, y1, z1};
    }

    public static List<double[]> rotate_points(List<double[]> points, double rx, double ry, double rz) {
        List<double[]> transformed_points = new ArrayList<>();
        for (double[] p : points) {
            transformed_points.add(transform_point(p[0], p[1], p[2], rx, ry, rz));
        }
        return transformed_points;
    }
}