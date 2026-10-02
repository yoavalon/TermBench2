public class sample_1880 {
    public static double calculate_altitude(double t, double v, double g, double h0) {
        double a = g * t;
        double h = h0 - 0.5 * a;
        return h;
    }

    public static void main(String[] args) {
        double t = 10.0;
        double v = 200.0;
        double g = 9.81;
        double h0 = 35000.0;
        double h = calculate_altitude(t, v, g, h0);
        System.out.println(h);
    }
}