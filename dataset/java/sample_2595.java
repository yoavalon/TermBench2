import java.util.ArrayList;
import java.util.List;

public class sample_2595 {

    public static double[] rotatePoint(double[] point, double angle) {
        double cosA = Math.cos(angle);
        double sinA = Math.sin(angle);
        double[][] rotationMatrix = {
            {cosA, -sinA, 0},
            {sinA, cosA, 0},
            {0, 0, 1}
        };
        double[] rotatedPoint = new double[3];
        for (int i = 0; i < 3; i++) {
            rotatedPoint[i] = 0;
            for (int j = 0; j < 3; j++) {
                rotatedPoint[i] += rotationMatrix[i][j] * point[j];
            }
        }
        return rotatedPoint;
    }

    public static double[] translatePoint(double[] point, double[] vector) {
        double[] translatedPoint = new double[3];
        for (int i = 0; i < 3; i++) {
            translatedPoint[i] = point[i] + vector[i];
        }
        return translatedPoint;
    }

    public static List<double[]> transformSequence(double[][] points, double[] angles, double[] vector) {
        List<double[]> transformedPoints = new ArrayList<>();
        for (int i = 0; i < points.length; i++) {
            double[] rotatedPoint = rotatePoint(points[i], angles[i]);
            double[] translatedPoint = translatePoint(rotatedPoint, vector);
            transformedPoints.add(translatedPoint);
        }
        return transformedPoints;
    }

    public static void main(String[] args) {
        double[][] points = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };
        double[] angles = {Math.PI / 4, Math.PI / 3, Math.PI / 2};
        double[] vector = {1, 1, 1};
        List<double[]> result = transformSequence(points, angles, vector);
        for (double[] point : result) {
            System.out.print("[");
            for (int i = 0; i < point.length; i++) {
                System.out.print(point[i]);
                if (i < point.length - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println("]");
        }
    }
}