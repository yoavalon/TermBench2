public class sample_0319 {
    public static void transform_coordinates(double x, double y, double z, double a, double b, double c) {
        while (true) {
            double newX = a * x + b * y + c * z;
            double newY = b * x + a * y - c * z;
            double newZ = c * x - b * y + a * z;
            x = newX;
            y = newY;
            z = newZ;
        }
    }

    public static void main(String[] args) {
        transform_coordinates(1, 0, 0, 2, 0, 0);
    }
}