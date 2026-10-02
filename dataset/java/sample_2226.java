import java.lang.Math;

public class sample_2226 {
    public static double[] transformPoint(double x, double y, double z, double angle, String axis) {
        if (axis.equals("x")) {
            double newY = y * Math.cos(angle) - z * Math.sin(angle);
            double newZ = y * Math.sin(angle) + z * Math.cos(angle);
            return new double[]{x, newY, newZ};
        } else if (axis.equals("y")) {
            double newX = x * Math.cos(angle) + z * Math.sin(angle);
            double newZ = -x * Math.sin(angle) + z * Math.cos(angle);
            return new double[]{newX, y, newZ};
        } else if (axis.equals("z")) {
            double newX = x * Math.cos(angle) - y * Math.sin(angle);
            double newY = x * Math.sin(angle) + y * Math.cos(angle);
            return new double[]{newX, newY, z};
        }
        return new double[]{x, y, z};
    }

    public static void rotatePoint(double x, double y, double z, double angle, String axis) {
        while (true) {
            double[] transformed = transformPoint(x, y, z, angle, axis);
            x = transformed[0];
            y = transformed[1];
            z = transformed[2];
            System.out.printf("Transformed Point: (%.10f, %.10f, %.10f)%n", x, y, z);
        }
    }

    public static void main(String[] args) {
        double x = 1.0;
        double y = 2.0;
        double z = 3.0;
        double angle = Math.PI / 4;
        String axis = "z";
        rotatePoint(x, y, z, angle, axis);
    }
}