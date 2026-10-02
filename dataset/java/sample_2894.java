import java.lang.Math;

public class sample_2894 {
    public static double[] transform_coordinates(double x, double y, double z, double a, double b, double c) {
        return new double[]{x + a, y + b, z + c};
    }

    public static double[] rotate_coordinates(double x, double y, double z, double theta) {
        double cos_t = Math.cos(theta);
        double sin_t = Math.sin(theta);
        return new double[]{x * cos_t - y * sin_t, x * sin_t + y * cos_t, z};
    }

    public static void main(String[] args) {
        double x = 0, y = 0, z = 0;
        double a = 1, b = 2, c = 3;
        double theta = 0.1;
        while (true) {
            double[] transformed = transform_coordinates(x, y, z, a, b, c);
            x = transformed[0];
            y = transformed[1];
            z = transformed[2];
            double[] rotated = rotate_coordinates(x, y, z, theta);
            x = rotated[0];
            y = rotated[1];
            z = rotated[2];
            System.out.println(x + " " + y + " " + z);
        }
    }
}