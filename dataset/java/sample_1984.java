import java.lang.Math;

public class sample_1984 {
    static double[] transform_coordinates(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double cos_a = Math.cos(rad);
        double sin_a = Math.sin(rad);
        double new_x = x * cos_a - y * sin_a;
        double new_y = x * sin_a + y * cos_a;
        double new_z = z;
        return new double[]{new_x, new_y, new_z};
    }

    static double calculate_distance(double x1, double y1, double z1, double x2, double y2, double z2) {
        return Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
    }

    public static void main(String[] args) {
        double x = 1.0, y = 2.0, z = 3.0;
        double angle = 30;
        double[] transformed = transform_coordinates(x, y, z, angle);
        double x_t = transformed[0], y_t = transformed[1], z_t = transformed[2];
        double d = calculate_distance(x, y, z, x_t, y_t, z_t);
        System.out.println("Transformed Coordinates: (" + x_t + ", " + y_t + ", " + z_t + ")");
        System.out.println("Distance: " + d);
    }
}