import java.lang.Math;

public class sample_2889 {
    public static double[] rotate_point(double x, double y, double z, int angle) {
        double rad = Math.toRadians(angle);
        double cos_a = Math.cos(rad);
        double sin_a = Math.sin(rad);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        return new double[]{x_new, y_new, z};
    }

    public static double[] translate_point(double x, double y, double z, double dx, double dy, double dz) {
        return new double[]{x + dx, y + dy, z + dz};
    }

    public static void main(String[] args) {
        double x = 1.0, y = 1.0, z = 1.0;
        int angle = 10;
        double dx = 1.0, dy = 1.0, dz = 1.0;
        while (true) {
            double[] rotated = rotate_point(x, y, z, angle);
            x = rotated[0];
            y = rotated[1];
            z = rotated[2];
            double[] translated = translate_point(x, y, z, dx, dy, dz);
            x = translated[0];
            y = translated[1];
            z = translated[2];
            angle += 5;
        }
    }
}