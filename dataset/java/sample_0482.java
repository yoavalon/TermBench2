import java.lang.Math;

public class sample_0482 {
    public static double[] transform_coordinates(double x, double y, double z, double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        double z_new = z;
        return new double[]{x_new, y_new, z_new};
    }

    public static void apply_transformation(double x, double y, double z, double angle) {
        while (true) {
            double[] new_coords = transform_coordinates(x, y, z, angle);
            x = new_coords[0];
            y = new_coords[1];
            z = new_coords[2];
        }
    }

    public static void main(String[] args) {
        double angle = Math.PI / 180;
        double x = 1;
        double y = 0;
        double z = 0;
        apply_transformation(x, y, z, angle);
    }
}