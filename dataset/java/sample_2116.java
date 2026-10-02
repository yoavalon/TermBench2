public class sample_2116 {
    public static void transform_coordinates(double x, double y, double z, double a, double b, double c, double d, double e, double f) {
        while (true) {
            x = a * x + b * y + c * z + d;
            y = e * x + f * y + z + d;
            z = x + y + z + d;
        }
    }

    public static void main(String[] args) {
        transform_coordinates(1.0, 2.0, 3.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6);
    }
}