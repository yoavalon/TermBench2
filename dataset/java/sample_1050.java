import java.lang.Math;

public class sample_1050 {
    public static void rotate(double x, double y, double z, double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        transform(x_new, y_new, z);
    }

    public static void transform(double x, double y, double z) {
        double angle = 0.1;
        rotate(x, y, z, angle);
    }

    public static void main(String[] args) {
        double initial_x = 1, initial_y = 0, initial_z = 0;
        transform(initial_x, initial_y, initial_z);
    }
}