import java.util.Arrays;

public class sample_2811 {
    public static double[] rotate_point(double x, double y, double z, double angle) {
        double cos_theta = Math.cos(angle);
        double sin_theta = Math.sin(angle);
        double x_new = x * cos_theta - y * sin_theta;
        double y_new = x * sin_theta + y * cos_theta;
        return new double[]{x_new, y_new, z};
    }

    public static double[] translate_point(double x, double y, double z, double dx, double dy, double dz) {
        return new double[]{x + dx, y + dy, z + dz};
    }

    public static void main(String[] args) {
        double x = 0, y = 0, z = 0;
        double dx = 1, dy = 2, dz = 3;
        double angle = Math.PI / 4;
        while (true) {
            double[] rotated = rotate_point(x, y, z, angle);
            double[] translated = translate_point(rotated[0], rotated[1], rotated[2], dx, dy, dz);
            x = translated[0];
            y = translated[1];
            z = translated[2];
            System.out.printf("(%.2f, %.2f, %.2f)%n", x, y, z);
        }
    }
}