public class sample_0073 {
    public static void main(String[] args) {
        double x = 1, y = 2, z = 3;
        double a = 0.5, b = 0.5, c = 0.707;
        double[] transformed = transform_coordinates(x, y, z, a, b, c);
        System.out.println(transformed[0] + " " + transformed[1] + " " + transformed[2]);
    }

    public static double[] transform_coordinates(double x, double y, double z, double a, double b, double c) {
        double x_prime = a * x + b * y + c * z;
        double y_prime = b * x + a * y + c * z;
        double z_prime = c * x + c * y + a * z;
        return new double[]{x_prime, y_prime, z_prime};
    }
}