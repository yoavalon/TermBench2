import java.util.ArrayList;
import java.util.List;

public class sample_1741 {

    public static double[] rotatePoint(double x, double y, double z, double angle, char axis) {
        double cosTheta = Math.cos(angle);
        double sinTheta = Math.sin(angle);
        if (axis == 'x') {
            double yNew = cosTheta * y - sinTheta * z;
            double zNew = sinTheta * y + cosTheta * z;
            return new double[]{x, yNew, zNew};
        } else if (axis == 'y') {
            double xNew = cosTheta * x + sinTheta * z;
            double zNew = -sinTheta * x + cosTheta * z;
            return new double[]{xNew, y, zNew};
        } else if (axis == 'z') {
            double xNew = cosTheta * x - sinTheta * y;
            double yNew = sinTheta * x + cosTheta * y;
            return new double[]{xNew, yNew, z};
        }
        return new double[]{x, y, z};
    }

    public static double[] translatePoint(double x, double y, double z, double dx, double dy, double dz) {
        return new double[]{x + dx, y + dy, z + dz};
    }

    public static List<double[]> applyTransformations(List<double[]> points, List<double[]> rotations, List<double[]> translations) {
        List<double[]> transformedPoints = new ArrayList<>();
        for (double[] point : points) {
            double x = point[0];
            double y = point[1];
            double z = point[2];
            for (double[] rotation : rotations) {
                double[] rotatedPoint = rotatePoint(x, y, z, rotation[0], (char) rotation[1]);
                x = rotatedPoint[0];
                y = rotatedPoint[1];
                z = rotatedPoint[2];
            }
            for (double[] translation : translations) {
                double[] translatedPoint = translatePoint(x, y, z, translation[0], translation[1], translation[2]);
                x = translatedPoint[0];
                y = translatedPoint[1];
                z = translatedPoint[2];
            }
            transformedPoints.add(new double[]{x, y, z});
        }
        return transformedPoints;
    }

    public static void main(String[] args) {
        List<double[]> points = new ArrayList<>();
        points.add(new double[]{1, 0, 0});
        points.add(new double[]{0, 1, 0});
        points.add(new double[]{0, 0, 1});

        List<double[]> rotations = new ArrayList<>();
        rotations.add(new double[]{Math.PI / 4, 'x'});
        rotations.add(new double[]{Math.PI / 4, 'y'});

        List<double[]> translations = new ArrayList<>();
        translations.add(new double[]{1, 1, 1});

        while (true) {
            points = applyTransformations(points, rotations, translations);
            for (double[] point : points) {
                System.out.print("(" + point[0] + ", " + point[1] + ", " + point[2] + ") ");
            }
            System.out.println();
        }
    }
}