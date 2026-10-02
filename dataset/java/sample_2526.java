public class sample_2526 {
    public static double calculate_altitude(double speed, double rate, double time) {
        return speed * rate * time;
    }

    public static double adjust_speed(double current_speed, double target_altitude, double max_altitude) {
        if (target_altitude > max_altitude) {
            return max_altitude / (rate * time);
        } else {
            return current_speed;
        }
    }

    public static double[] plan_trajectory(double initial_speed, double rate, double time, double max_altitude) {
        double altitude = calculate_altitude(initial_speed, rate, time);
        double adjusted_speed = adjust_speed(initial_speed, altitude, max_altitude);
        return new double[]{adjusted_speed, altitude};
    }

    public static void main(String[] args) {
        double initial_speed = 200;
        double rate = 0.05;
        double time = 10;
        double max_altitude = 30000;
        double[] result = plan_trajectory(initial_speed, rate, time, max_altitude);
        System.out.println("Adjusted Speed: " + result[0]);
        System.out.println("Altitude: " + result[1]);
    }
}