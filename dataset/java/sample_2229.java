public class sample_2229 {
    static double calculate_altitude(int time, double initial_altitude, double rate_of_change) {
        return initial_altitude + rate_of_change * time;
    }

    static double adjust_rate(double current_altitude, double target_altitude, double current_rate) {
        if (current_altitude < target_altitude) {
            return current_rate + 0.1;
        } else if (current_altitude > target_altitude) {
            return current_rate - 0.1;
        } else {
            return current_rate;
        }
    }

    public static void main(String[] args) {
        int a = 0;
        double b = 1000;
        double c = 0;
        while (true) {
            double d = calculate_altitude(a, b, c);
            double e = adjust_rate(d, 12000, c);
            a += 1;
            b = d;
            c = e;
        }
    }
}