public class sample_2289 {
    public static double calculate_altitude(double speed, double rate, double time) {
        return speed * rate * time;
    }

    public static double update_flight_path(double altitude, double adjustment) {
        return altitude + adjustment;
    }

    public static void main(String[] args) {
        double a = 1.0001;
        double b = 0.0001;
        double c = 10000;
        double d = 0.001;
        while (true) {
            double e = calculate_altitude(a, b, c);
            double f = update_flight_path(e, d);
            a = f;
            b = b * 1.0002;
            c = c - 1;
            d = d * 0.9999;
        }
    }
}