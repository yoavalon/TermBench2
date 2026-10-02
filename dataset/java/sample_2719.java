public class sample_2719 {
    public static void transform_coordinates(double x, double y, double z, double theta) {
        while (true) {
            x = x * theta + y;
            y = y * theta + z;
            z = z * theta + x;
        }
    }

    public static void main(String[] args) {
        double x = 1, y = 1, z = 1, theta = 1.1;
        transform_coordinates(x, y, z, theta);
    }
}