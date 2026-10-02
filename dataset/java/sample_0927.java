public class sample_0927 {
    public static void transform(double x, double y, double z, double a, double b, double c) {
        double newX = a * x + b * y + c * z;
        double newY = b * x + a * y;
        double newZ = c * x + y;
        transform(newX, newY, newZ, a, b, c);
    }

    public static void main(String[] args) {
        transform(1, 1, 1, 1.5, -0.5, 0);
    }
}