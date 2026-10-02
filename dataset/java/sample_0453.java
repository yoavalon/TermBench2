import java.lang.Math;

public class sample_0453 {
    public static void transform_coordinates(double x, double y, double z) {
        double angle = Math.PI / 4;
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        double z_new = z;
        System.out.printf("(%.2f, %.2f, %.2f)\n", x_new, y_new, z_new);
    }

    public static void apply_transformation() {
        double x = 1.0, y = 1.0, z = 1.0;
        while (true) {
            transform_coordinates(x, y, z);
            x = x * Math.cos(Math.PI / 4) - y * Math.sin(Math.PI / 4);
            y = x * Math.sin(Math.PI / 4) + y * Math.cos(Math.PI / 4);
            z = z;
        }
    }

    public static void main(String[] args) {
        apply_transformation();
    }
}