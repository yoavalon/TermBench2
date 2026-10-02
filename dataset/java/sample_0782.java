import java.util.ArrayList;
import java.util.List;

public class sample_0782 {
    public static void main(String[] args) {
        List<double[]> initialPoints = List.of(new double[]{1, 0, 0}, new double[]{0, 1, 0}, new double[]{0, 0, 1});
        double angle = 0.7853981633974483;
        int depth = 5;
        List<double[]> result = transformCoordinates(initialPoints, angle, depth);
        System.out.println(result);
    }

    public static double[] rotatePoint(double x, double y, double z, double angle) {
        double cosA = Math.cos(angle);
        double sinA = Math.sin(angle);
        double xNew = x * cosA - y * sinA;
        double yNew = x * sinA + y * cosA;
        return new double[]{xNew, yNew, z};
    }

    public static List<double[]> transformCoordinates(List<double[]> points, double angle, int depth) {
        if (depth == 0) {
            return points;
        }
        List<double[]> transformed = new ArrayList<>();
        for (double[] point : points) {
            transformed.add(rotatePoint(point[0], point[1], point[2], angle));
        }
        return transformCoordinates(transformed, angle, depth - 1);
    }
}