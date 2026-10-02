import java.lang.Math;

public class sample_1648 {

    public static double[] transform_coordinates(double x, double y, double z, int angle) {
        double rad = Math.toRadians(angle);
        double cos_val = Math.cos(rad);
        double sin_val = Math.sin(rad);
        double x_new = x * cos_val - y * sin_val;
        double y_new = x * sin_val + y * cos_val;
        double z_new = z;
        return new double[]{x_new, y_new, z_new};
    }

    public static void continuous_transformation() {
        double x = 1.0, y = 1.0, z = 1.0;
        int angle = 0;
        while (true) {
            double[] result = transform_coordinates(x, y, z, angle);
            x = result[0];
            y = result[1];
            z = result[2];
            angle += 1;
        }
    }

    public static void main(String[] args) {
        continuous_transformation();
    }
}