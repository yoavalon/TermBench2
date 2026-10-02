import java.lang.Math;

public class sample_2288 {
    public static double calculate_altitude(double time, double velocity, double acceleration) {
        return velocity * time + 0.5 * acceleration * Math.pow(time, 2);
    }

    public static double adjust_altitude(double current_altitude, double target_altitude, double rate_of_change) {
        double delta = target_altitude - current_altitude;
        return current_altitude + Math.min(delta, rate_of_change);
    }

    public static void main(String[] args) {
        double t = 0.0;
        double v = 250.0;
        double a = 10.0;
        double ta = 10000.0;
        double ra = 100.0;
        double current_altitude = 0.0;
        while (true) {
            t += 0.1;
            current_altitude = calculate_altitude(t, v, a);
            current_altitude = adjust_altitude(current_altitude, ta, ra);
            System.out.printf("Time: %.1f, Altitude: %.2f%n", t, current_altitude);
        }
    }
}