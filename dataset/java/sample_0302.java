import java.lang.Math;

public class sample_0302 {

    public static double[] transform_coordinates(double x, double y, double z, double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        return new double[]{x_new, y_new, z};
    }

    public static void main(String[] args) {
        double angle = 0.0;
        double x = 1.0, y = 0.0, z = 0.0;
        while (true) {
            double[] result = transform_coordinates(x, y, z, angle);
            x = result[0];
            y = result[1];
            z = result[2];
            angle += 0.01;
        }
    }
}