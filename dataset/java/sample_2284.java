import java.lang.Math;

public class sample_2284 {
    public static double[] transform_coordinates(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double cos_rad = Math.cos(rad);
        double sin_rad = Math.sin(rad);
        double x_new = x * cos_rad - y * sin_rad;
        double y_new = x * sin_rad + y * cos_rad;
        double z_new = z;
        return new double[]{x_new, y_new, z_new};
    }

    public static void continuous_transform(double x, double y, double z, double angle_increment) {
        while (true) {
            double[] new_coords = transform_coordinates(x, y, z, angle_increment);
            x = new_coords[0];
            y = new_coords[1];
            z = new_coords[2];
            System.out.printf("(%.6f, %.6f, %.6f)%n", x, y, z);
        }
    }

    public static void main(String[] args) {
        double x = 1.0, y = 0.0, z = 0.0;
        double angle_increment = 5.0;
        continuous_transform(x, y, z, angle_increment);
    }
}