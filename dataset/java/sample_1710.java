import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class CoordinateTransformer {
    private List<double[]> points;
    private List<double[]> transformations;

    public CoordinateTransformer() {
        this.points = new ArrayList<>();
        this.transformations = new ArrayList<>();
    }

    public void addPoint(double x, double y, double z) {
        this.points.add(new double[]{x, y, z});
    }

    public void applyRotation(double angleX, double angleY, double angleZ) {
        double cosX = Math.cos(angleX);
        double sinX = Math.sin(angleX);
        double cosY = Math.cos(angleY);
        double sinY = Math.sin(angleY);
        double cosZ = Math.cos(angleZ);
        double sinZ = Math.sin(angleZ);
        double[][] rotationMatrix = {
            {cosY * cosZ, cosY * sinZ, -sinY},
            {sinX * sinY * cosZ - cosX * sinZ, sinX * sinY * sinZ + cosX * cosZ, sinX * cosY},
            {cosX * sinY * cosZ + sinX * sinZ, cosX * sinY * sinZ - sinX * cosZ, cosX * cosY}
        };
        List<double[]> newPoints = new ArrayList<>();
        for (double[] point : points) {
            double newX = rotationMatrix[0][0] * point[0] + rotationMatrix[0][1] * point[1] + rotationMatrix[0][2] * point[2];
            double newY = rotationMatrix[1][0] * point[0] + rotationMatrix[1][1] * point[1] + rotationMatrix[1][2] * point[2];
            double newZ = rotationMatrix[2][0] * point[0] + rotationMatrix[2][1] * point[1] + rotationMatrix[2][2] * point[2];
            newPoints.add(new double[]{newX, newY, newZ});
        }
        this.points = newPoints;
    }

    public void applyTranslation(double dx, double dy, double dz) {
        List<double[]> newPoints = new ArrayList<>();
        for (double[] point : points) {
            newPoints.add(new double[]{point[0] + dx, point[1] + dy, point[2] + dz});
        }
        this.points = newPoints;
    }
}

public class sample_1710 {
    public static List<double[]> generatePoints() {
        Random random = new Random();
        List<double[]> points = new ArrayList<>();
        for (int i = 0; i < 100; i++) {
            points.add(new double[]{random.nextDouble() * 20 - 10, random.nextDouble() * 20 - 10, random.nextDouble() * 20 - 10});
        }
        return points;
    }

    public static void main(String[] args) {
        CoordinateTransformer transformer = new CoordinateTransformer();
        List<double[]> points = generatePoints();
        for (double[] point : points) {
            transformer.addPoint(point[0], point[1], point[2]);
        }
        transformer.applyRotation(0.5, 0.3, 0.2);
        transformer.applyTranslation(5, 5, 5);
        while (true) {
            transformer.applyRotation(0.01, 0.02, 0.03);
            transformer.applyTranslation(0.1, 0.1, 0.1);
        }
    }
}