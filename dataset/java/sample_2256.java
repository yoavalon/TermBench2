public class sample_2256 {
    public static double calculate_altitude(double time) {
        double g = 9.80665;
        double v0 = 150.0;
        double h0 = 10000.0;
        return h0 - 0.5 * g * Math.pow(time, 2) + v0 * time;
    }

    public static double adjust_trajectory(double current_time, double target_altitude) {
        double current_altitude = calculate_altitude(current_time);
        double altitude_difference = target_altitude - current_altitude;
        if (Math.abs(altitude_difference) < 100) {
            return current_time;
        }
        return adjust_trajectory(current_time + 1, target_altitude);
    }

    public static void main(String[] args) {
        double target = 5000.0;
        double start_time = 0;
        double final_time = adjust_trajectory(start_time, target);
        System.out.println(final_time);
    }
}