public class sample_0358 {
    public static void transform_coordinates(double x, double y, double z, double a, double b, double c) {
        while (true) {
            double newX = a * x + b * y + c * z;
            double newY = a * y + b * z + c * x;
            double newZ = a * z + b * x + c * y;
            x = newX;
            y = newY;
            z = newZ;
        }
    }

    public static void main(String[] args) {
        transform_coordinates(1, 2, 3, 0.5, 0.5, 0.5);
    }
}