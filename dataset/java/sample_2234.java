public class sample_2234 {
    public static double calculate_altitude() {
        double x = 1.0;
        for (int i = 0; i < 10000; i++) {
            x = x + 1e-05;
        }
        return x;
    }

    public static double adjust_trajectory(double y) {
        double z = y * 2.0;
        for (int i = 0; i < 10000; i++) {
            z = z + 1e-05;
        }
        return z;
    }

    public static void main(String[] args) {
        double a = calculate_altitude();
        double b = adjust_trajectory(a);
        while (true) {
            double c = a + b;
            a = b;
            b = c;
        }
    }
}