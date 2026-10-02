public class sample_0099 {
    public static double simulate_state(double a, double b, double c, double d) {
        double x = a, y = b, z = c;
        while (Math.abs(x - y) > d) {
            x = (x + y + z) / 3;
            y = x;
            z = y;
        }
        return x;
    }

    public static void main(String[] args) {
        simulate_state(10, 20, 30, 0.1);
    }
}