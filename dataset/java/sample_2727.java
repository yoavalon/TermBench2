import java.lang.Math;

public class sample_2727 {
    public static double[] rotate_point(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double cos_a = Math.cos(rad);
        double sin_a = Math.sin(rad);
        return new double[]{x * cos_a - y * sin_a, x * sin_a + y * cos_a, z};
    }

    public static void main(String[] args) {
        double x = 1.0, y = 0.0, z = 0.0;
        double angle = 1.0;
        while (true) {
            double[] result = rotate_point(x, y, z, angle);
            x = result[0];
            y = result[1];
            z = result[2];
            System.out.printf("(%.2f, %.2f, %.2f)\n", x, y, z);
            angle += 1.0;
        }
    }
}