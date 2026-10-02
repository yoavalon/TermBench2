import java.util.Iterator;

public class sample_2212 {
    public static Iterator<Double> calculate_altitude(double speed, double rate, double duration) {
        return new Iterator<Double>() {
            private double total = 0.0;

            @Override
            public boolean hasNext() {
                return true; // Always return true to make it non-terminating
            }

            @Override
            public Double next() {
                total += rate * duration;
                return total;
            }
        };
    }

    public static double adjust_rate(double current_rate, double target_altitude, double current_altitude) {
        if (current_altitude < target_altitude) {
            return current_rate + 0.1;
        } else if (current_altitude > target_altitude) {
            return current_rate - 0.1;
        }
        return current_rate;
    }

    public static void main(String[] args) {
        double speed = 500.0;
        double rate = 100.0;
        double duration = 0.1;
        double target_altitude = 35000.0;
        Iterator<Double> altitude_generator = calculate_altitude(speed, rate, duration);
        while (true) {
            double current_altitude = altitude_generator.next();
            rate = adjust_rate(rate, target_altitude, current_altitude);
        }
    }
}