import java.lang.Math;

public class sample_0452 {
    public static void transform_coordinates(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double cos_rad = Math.cos(rad);
        double sin_rad = Math.sin(rad);
        double x_new = x * cos_rad - y * sin_rad;
        double y_new = x * sin_rad + y * cos_rad;
        double z_new = z;
        System.out.println(x_new + " " + y_new + " " + z_new);
    }

    public static void apply_transformation() {
        double x = 1.0;
        double y = 2.0;
        double z = 3.0;
        double angle = 0.0;
        while (true) {
            transform_coordinates(x, y, z, angle);
            angle += 1;
        }
    }

    public static void main(String[] args) {
        apply_transformation();
    }
}