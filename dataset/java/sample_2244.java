import java.lang.Math;

public class sample_2244 {
    public static void transform_coordinates(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double cos_a = Math.cos(rad);
        double sin_a = Math.sin(rad);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        System.out.println("(" + x_new + ", " + y_new + ", " + z + ")");
    }

    public static void infinite_rotation(double x, double y, double z, double angle_step) {
        double angle = 0;
        while (true) {
            transform_coordinates(x, y, z, angle);
            angle += angle_step;
        }
    }

    public static void main(String[] args) {
        double x = 1, y = 1, z = 1;
        double angle_step = 5;
        infinite_rotation(x, y, z, angle_step);
    }
}