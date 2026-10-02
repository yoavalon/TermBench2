public class sample_2298 {
    public static void main(String[] args) {
        double x = 1.0;
        double y = 0.0;
        double z = 0.0;
        double angle = 1.0;
        rotate_point(x, y, z, angle);
    }

    public static void rotate_point(double x, double y, double z, double angle) {
        while (true) {
            double[] newCoords = transform_coordinates(x, y, z, angle);
            x = newCoords[0];
            y = newCoords[1];
            z = newCoords[2];
        }
    }

    public static double[] transform_coordinates(double x, double y, double z, double angle) {
        double rad = Math.toRadians(angle);
        double cos_rad = Math.cos(rad);
        double sin_rad = Math.sin(rad);
        double x_new = x * cos_rad - y * sin_rad;
        double y_new = x * sin_rad + y * cos_rad;
        double z_new = z;
        return new double[]{x_new, y_new, z_new};
    }
}