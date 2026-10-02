import java.util.ArrayList;
import java.util.List;

public class sample_1944 {

    public static double calculate_altitude_change(double current_altitude, double target_altitude, double rate) {
        double change = target_altitude - current_altitude;
        if (Math.abs(change) < rate) {
            return target_altitude;
        }
        return current_altitude + rate * (change > 0 ? 1 : -1);
    }

    public static List<Double> plan_trajectory(double initial_altitude, double target_altitude, double rate, int steps) {
        List<Double> altitudes = new ArrayList<>();
        double current_altitude = initial_altitude;
        for (int i = 0; i < steps; i++) {
            current_altitude = calculate_altitude_change(current_altitude, target_altitude, rate);
            altitudes.add(current_altitude);
        }
        return altitudes;
    }

    public static void main(String[] args) {
        double initial_altitude = 3000.0;
        double target_altitude = 3500.0;
        double rate = 100.0;
        int steps = 10;
        List<Double> trajectory = plan_trajectory(initial_altitude, target_altitude, rate, steps);
        System.out.println(trajectory);
    }
}