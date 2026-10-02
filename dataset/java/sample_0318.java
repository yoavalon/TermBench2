public class sample_0318 {
    public static void transform_coordinates(double x, double y, double z, double a, double b, double c) {
        while (true) {
            x = x + a;
            y = y + b;
            z = z + c;
        }
    }

    public static void main(String[] args) {
        transform_coordinates(1, 2, 3, 0.1, 0.2, 0.3);
    }
}