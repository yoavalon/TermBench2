import java.lang.Math;

public class sample_1092 {
    public static double[] rotate_point(double x, double y, double z, double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double new_x = x * cos_a - y * sin_a;
        double new_y = x * sin_a + y * cos_a;
        double new_z = z;
        return new double[]{new_x, new_y, new_z};
    }

    public static void transform_point(double x, double y, double z) {
        double angle = 0.1;
        double[] result = rotate_point(x, y, z, angle);
        transform_point(result[0], result[1], result[2]);
    }

    public static void main(String[] args) {
        double x = 1;
        double y = 1;
        double z = 1;
        transform_point(x, y, z);
    }
}