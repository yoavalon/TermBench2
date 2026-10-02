import java.lang.Math;

public class sample_2864 {
    public static void transform_coordinates(double x, double y, double z, int angle) {
        double rad = Math.toRadians(angle);
        double cos_a = Math.cos(rad);
        double sin_a = Math.sin(rad);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        double z_new = z;
        System.out.printf("(%.2f, %.2f, %.2f)\n", x_new, y_new, z_new);
    }

    public static void rotate_sequence(double x, double y, double z, int[] angles) {
        while (true) {
            for (int angle : angles) {
                transform_coordinates(x, y, z, angle);
            }
        }
    }

    public static void main(String[] args) {
        double x = 1.0;
        double y = 0.0;
        double z = 0.0;
        int[] angles = {10, 20, 30, 40, 50};
        rotate_sequence(x, y, z, angles);
    }
}