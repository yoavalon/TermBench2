public class sample_1838 {
    public static double[] transform_coordinates(double x, double y, double z, double angle) {
        double cos_a = Math.cos(angle);
        double sin_a = Math.sin(angle);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        double z_new = z;
        return new double[]{x_new, y_new, z_new};
    }

    public static void main(String[] args) {
        double x = 1.0, y = 2.0, z = 3.0;
        double angle = Math.PI / 4;
        double[] transformed = transform_coordinates(x, y, z, angle);
        System.out.println(transformed[0] + " " + transformed[1] + " " + transformed[2]);
    }
}