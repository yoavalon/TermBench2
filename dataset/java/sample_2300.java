import java.util.ArrayList;
import java.util.List;

public class sample_2300 {

    public static double[] rotatePoint(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double cos_a = Math.cos(rad);
        double sin_a = Math.sin(rad);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        double z_new = z;
        return new double[]{x_new, y_new, z_new};
    }

    public static List<double[]> transformSequence(List<double[]> points, double angle) {
        List<double[]> result = new ArrayList<>();
        for (double[] p : points) {
            double[] newPoint = rotatePoint(p[0], p[1], p[2], angle);
            result.add(newPoint);
        }
        return result;
    }

    public static void main(String[] args) {
        List<double[]> points = new ArrayList<>();
        points.add(new double[]{1, 0, 0});
        points.add(new double[]{0, 1, 0});
        points.add(new double[]{0, 0, 1});
        double angle = 10;
        while (true) {
            points = transformSequence(points, angle);
            angle += 5;
        }
    }
}