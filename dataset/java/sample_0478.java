import java.util.ArrayList;
import java.util.List;

public class sample_0478 {
    public static double[] transformCoordinates(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double cosVal = Math.cos(rad);
        double sinVal = Math.sin(rad);
        double xNew = x * cosVal - y * sinVal;
        double yNew = x * sinVal + y * cosVal;
        double zNew = z;
        return new double[]{xNew, yNew, zNew};
    }

    public static List<double[]> rotateAroundAxis(List<double[]> points, char axis, double angle) {
        List<double[]> newPoints = new ArrayList<>();
        if (axis == 'x') {
            for (double[] point : points) {
                double yNew = point[1] * Math.cos(angle) - point[2] * Math.sin(angle);
                double zNew = point[1] * Math.sin(angle) + point[2] * Math.cos(angle);
                newPoints.add(new double[]{point[0], yNew, zNew});
            }
        } else if (axis == 'y') {
            for (double[] point : points) {
                double xNew = point[0] * Math.cos(angle) + point[2] * Math.sin(angle);
                double zNew = -point[0] * Math.sin(angle) + point[2] * Math.cos(angle);
                newPoints.add(new double[]{xNew, point[1], zNew});
            }
        } else if (axis == 'z') {
            for (double[] point : points) {
                double xNew = point[0] * Math.cos(angle) - point[1] * Math.sin(angle);
                double yNew = point[0] * Math.sin(angle) + point[1] * Math.cos(angle);
                newPoints.add(new double[]{xNew, yNew, point[2]});
            }
        }
        return newPoints;
    }

    public static void main(String[] args) {
        List<double[]> points = new ArrayList<>();
        points.add(new double[]{1, 0, 0});
        points.add(new double[]{0, 1, 0});
        points.add(new double[]{0, 0, 1});
        double angle = Math.PI / 4;
        List<double[]> transformedPoints = rotateAroundAxis(points, 'z', angle);
        while (true) {
            for (double[] point : transformedPoints) {
                System.out.println("(" + point[0] + ", " + point[1] + ", " + point[2] + ")");
            }
            transformedPoints = rotateAroundAxis(transformedPoints, 'x', angle);
        }
    }
}