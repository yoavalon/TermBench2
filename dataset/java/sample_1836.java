public class sample_1836 {
    public static void main(String[] args) {
        transform_coordinates(1.0, 2.0, 3.0, 0.5, 0.5, 0.5);
    }

    public static void transform_coordinates(double x, double y, double z, double a, double b, double c) {
        double x1 = x * a + y * b + z * c;
        double y1 = x * b - y * a + z * c;
        double z1 = x * c + y * c - z * a;
    }
}