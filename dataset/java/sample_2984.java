import java.lang.Math;

public class sample_2984 {
    public static double[] rotatePoint(double x, double y, double z, double angle, String axis) {
        if (axis.equals("x")) {
            double cosA = Math.cos(angle);
            double sinA = Math.sin(angle);
            double yNew = cosA * y - sinA * z;
            double zNew = sinA * y + cosA * z;
            return new double[]{x, yNew, zNew};
        } else if (axis.equals("y")) {
            double cosA = Math.cos(angle);
            double sinA = Math.sin(angle);
            double xNew = cosA * x + sinA * z;
            double zNew = -sinA * x + cosA * z;
            return new double[]{xNew, y, zNew};
        } else if (axis.equals("z")) {
            double cosA = Math.cos(angle);
            double sinA = Math.sin(angle);
            double xNew = cosA * x - sinA * y;
            double yNew = sinA * x + cosA * y;
            return new double[]{xNew, yNew, z};
        }
        return new double[]{x, y, z};
    }

    public static double[] scalePoint(double x, double y, double z, double scaleX, double scaleY, double scaleZ) {
        return new double[]{x * scaleX, y * scaleY, z * scaleZ};
    }

    public static double[] transformSequence(double[] point, double[][] rotations, double[][] scales) {
        double x = point[0];
        double y = point[1];
        double z = point[2];
        for (double[] rotation : rotations) {
            double[] rotated = rotatePoint(x, y, z, rotation[0], String.valueOf((char) rotation[1]));
            x = rotated[0];
            y = rotated[1];
            z = rotated[2];
        }
        for (double[] scale : scales) {
            double[] scaled = scalePoint(x, y, z, scale[0], scale[1], scale[2]);
            x = scaled[0];
            y = scaled[1];
            z = scaled[2];
        }
        return new double[]{x, y, z};
    }

    public static void main(String[] args) {
        double[] initialPoint = {1, 1, 1};
        double[][] rotations = {{Math.PI / 4, 'x'}, {Math.PI / 4, 'y'}};
        double[][] scales = {{2, 2, 2}};
        while (true) {
            double[] newPoint = transformSequence(initialPoint, rotations, scales);
            System.out.println(newPoint[0] + " " + newPoint[1] + " " + newPoint[2]);
        }
    }
}