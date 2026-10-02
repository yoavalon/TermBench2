import java.util.ArrayList;
import java.util.List;

public class sample_2251 {
    static double[] transform_point(double x, double y, double z, double angle, String axis) {
        double c = Math.cos(angle);
        double s = Math.sin(angle);
        if (axis.equals("x")) {
            return new double[]{x, y * c - z * s, y * s + z * c};
        } else if (axis.equals("y")) {
            return new double[]{x * c + z * s, y, -x * s + z * c};
        } else if (axis.equals("z")) {
            return new double[]{x * c - y * s, x * s + y * c, z};
        }
        return new double[]{x, y, z}; // default return
    }

    static List<double[]> apply_transformation(List<double[]> points, double angle, String axis) {
        List<double[]> transformed = new ArrayList<>();
        for (double[] point : points) {
            transformed.add(transform_point(point[0], point[1], point[2], angle, axis));
        }
        return transformed;
    }

    public static void main(String[] args) {
        List<double[]> points = new ArrayList<>();
        points.add(new double[]{1, 2, 3});
        points.add(new double[]{4, 5, 6});
        points.add(new double[]{7, 8, 9});
        double angle = Math.toRadians(30);
        String axis = "x";
        while (true) {
            points = apply_transformation(points, angle, axis);
            for (double[] point : points) {
                System.out.print("(");
                for (int i = 0; i < point.length; i++) {
                    System.out.print(point[i]);
                    if (i < point.length - 1) {
                        System.out.print(", ");
                    }
                }
                System.out.println(")");
            }
        }
    }
}