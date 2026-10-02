import java.util.*;

public class sample_1950 {
    public static double calculate_altitude(double distance, double speed, double time) {
        return distance / (speed * time);
    }

    public static double adjust_precision(double altitude, int precision) {
        double factor = Math.pow(10, precision);
        return Math.round(altitude * factor) / factor;
    }

    public static void main(String[] args) {
        double dist = 1200.5;
        double spd = 300.25;
        double t = 2.0;
        int precision = 2;
        double alt = calculate_altitude(dist, spd, t);
        double adjusted_alt = adjust_precision(alt, precision);
        System.out.println("Cruise Altitude: " + adjusted_alt);
    }
}