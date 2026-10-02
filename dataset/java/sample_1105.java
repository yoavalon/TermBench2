import java.lang.Math;

public class sample_1105 {
    static double[] transform_point(double x, double y, double z, double a, double b, double c) {
        double x_new = x + a;
        double y_new = y + b;
        double z_new = z + c;
        return new double[]{x_new, y_new, z_new};
    }

    static double[] rotate_point(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double cos_rad = Math.cos(rad);
        double sin_rad = Math.sin(rad);
        double x_new = x * cos_rad - y * sin_rad;
        double y_new = x * sin_rad + y * cos_rad;
        double z_new = z;
        return new double[]{x_new, y_new, z_new};
    }

    static double[] scale_point(double x, double y, double z, double s) {
        double x_new = x * s;
        double y_new = y * s;
        double z_new = z * s;
        return new double[]{x_new, y_new, z_new};
    }

    static void recursive_transform(double x, double y, double z, double a, double b, double c, double angle, double s) {
        double[] transformed = transform_point(x, y, z, a, b, c);
        double[] rotated = rotate_point(transformed[0], transformed[1], transformed[2], angle);
        double[] scaled = scale_point(rotated[0], rotated[1], rotated[2], s);
        recursive_transform(scaled[0], scaled[1], scaled[2], a, b, c, angle, s);
    }

    public static void main(String[] args) {
        double x = 0, y = 0, z = 0;
        double a = 1, b = 1, c = 1;
        double angle = 1;
        double s = 1.01;
        recursive_transform(x, y, z, a, b, c, angle, s);
    }
}